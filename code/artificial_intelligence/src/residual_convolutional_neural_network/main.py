import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.tensorboard import SummaryWriter
from torchvision import datasets, transforms
from sklearn import metrics
import numpy as np
from tqdm import tqdm


class params:
    batch_size = 1024
    epochs = 100
    lr = 1e-3


class Block(nn.Module):
    def __init__(self, in_channels, out_channels):
        super(Block, self).__init__()
        self.conv1 = nn.Conv2d(in_channels, out_channels, 3, 1, 1)
        self.bn1 = nn.BatchNorm2d(out_channels)

        self.conv2 = nn.Conv2d(out_channels, out_channels, 3, 1, 1)
        self.bn2 = nn.BatchNorm2d(out_channels)

        self.shortcut = (
            nn.Sequential()
            if in_channels == out_channels
            else nn.Sequential(
                nn.Conv2d(in_channels, out_channels, 1, bias=False),
                nn.BatchNorm2d(out_channels),
            )
        )

    def forward(self, x):
        out = F.relu(self.bn1(self.conv1(x)))
        out = self.bn2(self.conv2(out))

        out += self.shortcut(x)

        out = F.relu(out)
        return out


class ConvNet(nn.Module):
    def __init__(self, num_classes=10):
        super(ConvNet, self).__init__()
        structure = [
            (3, 64),
            64,
            "p",
            (64, 128),
            128,
            "p",
            (128, 256),
            256,
            "p",
            (256, 512),
            512,
        ]

        layers = []

        for layer in structure:
            if layer == "p":
                layers.append(nn.MaxPool2d(2))
            elif isinstance(layer, tuple):
                layers.append(Block(layer[0], layer[1]))
            else:
                layers.append(Block(layer, layer))

        self.conv = nn.Sequential(*layers)
        self.avgpool = nn.AdaptiveAvgPool2d((1, 1))
        self.dropout = nn.Dropout()
        self.fc = nn.Linear(512, num_classes)

    def forward(self, x):
        x = self.conv(x)
        x = self.avgpool(x)

        x = torch.flatten(x, 1)
        x = self.dropout(x)

        x = self.fc(x)
        x = F.log_softmax(x, 1)

        return x


is_cuda = torch.cuda.is_available()
print(f"Using {'GPU' if is_cuda else 'CPU'}")
device = torch.device("cuda" if is_cuda else "cpu")

kwargs = {"batch_size": params.batch_size}
if is_cuda:
    kwargs.update({"num_workers": 1, "pin_memory": True, "shuffle": True})

transform = transforms.Compose([transforms.ToTensor()])

train_set = datasets.CIFAR10("./data", train=True, download=True, transform=transform)
test_set = datasets.CIFAR10("./data", train=False, transform=transform)

train_loader = torch.utils.data.DataLoader(train_set, **kwargs)
test_loader = torch.utils.data.DataLoader(test_set, **kwargs)

label_names = [
    "airplane",
    "automobile",
    "bird",
    "cat",
    "deer",
    "dog",
    "frog",
    "horse",
    "ship",
    "truck",
]
metric_names = ["loss", "accuracy"]

model = ConvNet(num_classes=10)
model.to(device)

num_params = sum(p.numel() for p in model.parameters() if p.requires_grad)
print(f"Parameters: {num_params}")

optimizer = torch.optim.Adam(model.parameters(), lr=params.lr)

writer = SummaryWriter(log_dir="./logs")
temp_ipt = torch.rand(5, 3, 32, 32, device=device)

writer.add_graph(model, temp_ipt)

for epoch in range(params.epochs):
    model.train()

    train_metrics = [0, 0]

    for idx, (data, target) in tqdm(
        enumerate(train_loader), f"Epoch: {epoch + 1}", total=len(train_loader)
    ):
        data, target = data.to(device), target.to(device)

        optimizer.zero_grad()
        output = model(data)

        loss = F.nll_loss(output, target)
        loss.backward()
        optimizer.step()

        train_metrics[0] += loss.item()

        output = output.cpu().detach().numpy()
        target = target.cpu().detach().numpy()
        output = np.argmax(output, 1)

        train_metrics[1] += metrics.accuracy_score(y_true=target, y_pred=output)

    train_metrics = np.array(train_metrics) / len(train_loader)
    for name, val in zip(metric_names, train_metrics):
        writer.add_scalar("train/" + name, val, epoch)

    test_metrics = [0, 0]
    model.eval()
    with torch.no_grad():
        for data, target in test_loader:
            data, target = data.to(device), target.to(device)
            output = model(data)

            test_metrics[0] += F.nll_loss(output, target).item()

            output = output.cpu().detach().numpy()
            target = target.cpu().detach().numpy()
            output = np.argmax(output, 1)

            test_metrics[1] += metrics.accuracy_score(y_true=target, y_pred=output)

    test_metrics = np.array(test_metrics) / len(test_loader)
    for name, val in zip(metric_names, test_metrics):
        writer.add_scalar("test/" + name, val, epoch)
