import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.tensorboard import SummaryWriter
from torchvision.utils import make_grid
from torchvision import datasets, transforms
import numpy as np
from tqdm import tqdm


class params:
    batch_size = 8192
    latent_dim = 4
    epochs = 100
    lr = 5e-3


class AE(nn.Module):
    def __init__(self):
        super(AE, self).__init__()
        self.conv1 = nn.Conv2d(1, 16, 3, padding=1)
        self.conv2 = nn.Conv2d(16, 4, 3, padding=1)
        self.pool = nn.MaxPool2d(2, 2)

        self.t_conv1 = nn.ConvTranspose2d(4, 16, 2, stride=2)
        self.t_conv2 = nn.ConvTranspose2d(16, 1, 2, stride=2)

    def forward(self, x):
        x = F.relu(self.conv1(x))
        x = self.pool(x)
        x = F.relu(self.conv2(x))
        x = self.pool(x)

        x = F.relu(self.t_conv1(x))
        x = F.sigmoid(self.t_conv2(x))
        return x


is_cuda = True
device = torch.device("cuda" if is_cuda else "cpu")
print(f"Running on {device}")

kwargs = {"batch_size": params.batch_size}
if is_cuda:
    kwargs.update({"num_workers": 1, "pin_memory": True, "shuffle": True})

transform = transforms.Compose([transforms.ToTensor()])

train_set = datasets.MNIST("../../data", train=True, download=True, transform=transform)
test_set = datasets.MNIST("../../data", train=False, transform=transform)

train_loader = torch.utils.data.DataLoader(train_set, **kwargs)
test_loader = torch.utils.data.DataLoader(test_set, **kwargs)

metric_names = ["loss"]

model = AE()
model.to(device)

num_params = sum(p.numel() for p in model.parameters() if p.requires_grad)
print(f"Parameters: {num_params}")

criterion = nn.BCELoss()
optimizer = torch.optim.Adam(model.parameters(), lr=params.lr)

writer = SummaryWriter(log_dir="./logs")

temp_ipt = torch.rand(5, 1, 28, 28, device=device)
writer.add_graph(model, temp_ipt)

for epoch in range(params.epochs):
    model.train()

    train_metrics = [0]

    for idx, (data, _) in tqdm(
        enumerate(train_loader), f"Epoch: {epoch + 1}", total=len(train_loader)
    ):
        data = data.to(device)

        optimizer.zero_grad()
        output = model(data)

        loss = criterion(output, data)

        loss.backward()
        optimizer.step()

        train_metrics[0] += loss.item()

    train_metrics = np.array(train_metrics) / len(train_loader)
    for name, val in zip(metric_names, train_metrics):
        writer.add_scalar("train/" + name, val, epoch)

    test_metrics = [0]
    model.eval()

    test_outputs = []

    with torch.no_grad():
        for data, _ in test_loader:
            data = data.to(device)
            output = model(data)

            test_metrics[0] += criterion(output, data)
            test_outputs = output

    grid = make_grid(test_outputs[:64])
    writer.add_image("test/reconstructed", grid, epoch)

    test_metrics = np.array(test_metrics) / len(test_loader)
    for name, val in zip(metric_names, test_metrics):
        writer.add_scalar("test/" + name, val, epoch)
