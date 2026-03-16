"""
Recurrent Neural Network (RNN) from scratch using NumPy.

This implementation demonstrates a vanilla RNN for sequence classification
trained on synthetic sequential data. It includes forward propagation through
time, backpropagation through time (BPTT), and gradient clipping.

Part of Cosmos by OpenGenus Foundation.
"""

import numpy as np


class RNN:
    """A vanilla Recurrent Neural Network for sequence classification."""

    def __init__(self, input_size, hidden_size, output_size, learning_rate=0.01):
        """
        Initialize RNN parameters.

        Args:
            input_size: Dimension of input at each time step.
            hidden_size: Number of hidden units.
            output_size: Number of output classes.
            learning_rate: Step size for gradient descent.
        """
        self.hidden_size = hidden_size
        self.learning_rate = learning_rate

        # Small-scale initialization for RNN stability
        scale = 0.01
        self.Wxh = np.random.randn(input_size, hidden_size) * scale
        self.Whh = np.random.randn(hidden_size, hidden_size) * scale
        self.Why = np.random.randn(hidden_size, output_size) * scale

        self.bh = np.zeros((1, hidden_size))
        self.by = np.zeros((1, output_size))

    def _tanh(self, x):
        return np.tanh(x)

    def _softmax(self, x):
        exp_x = np.exp(x - np.max(x, axis=1, keepdims=True))
        return exp_x / np.sum(exp_x, axis=1, keepdims=True)

    def forward(self, inputs):
        """
        Forward pass through the sequence.

        Args:
            inputs: Array of shape (sequence_length, batch_size, input_size).

        Returns:
            output: Softmax probabilities of shape (batch_size, output_size).
            hidden_states: List of hidden states at each time step.
        """
        batch_size = inputs.shape[1]
        h = np.zeros((batch_size, self.hidden_size))
        hidden_states = [h]

        for t in range(inputs.shape[0]):
            x_t = inputs[t]
            h = self._tanh(x_t @ self.Wxh + h @ self.Whh + self.bh)
            hidden_states.append(h)

        output = self._softmax(h @ self.Why + self.by)
        return output, hidden_states

    def backward(self, inputs, hidden_states, output, labels):
        """
        Backpropagation through time (BPTT).

        Args:
            inputs: Input sequence (sequence_length, batch_size, input_size).
            hidden_states: Hidden states from forward pass.
            output: Predicted probabilities (batch_size, output_size).
            labels: One-hot encoded labels (batch_size, output_size).

        Returns:
            loss: Cross-entropy loss value.
        """
        batch_size = inputs.shape[1]
        seq_len = inputs.shape[0]

        # Cross-entropy loss
        loss = -np.sum(labels * np.log(output + 1e-8)) / batch_size

        # Gradient of loss w.r.t. output
        dy = (output - labels) / batch_size

        # Gradients for output layer
        dWhy = hidden_states[-1].T @ dy
        dby = np.sum(dy, axis=0, keepdims=True)

        # Backpropagate through time
        dWxh = np.zeros_like(self.Wxh)
        dWhh = np.zeros_like(self.Whh)
        dbh = np.zeros_like(self.bh)

        dh_next = dy @ self.Why.T

        for t in reversed(range(seq_len)):
            # Gradient through tanh: d_tanh = (1 - tanh^2) * upstream
            dtanh = (1 - hidden_states[t + 1] ** 2) * dh_next

            dWxh += inputs[t].T @ dtanh
            dWhh += hidden_states[t].T @ dtanh
            dbh += np.sum(dtanh, axis=0, keepdims=True)

            dh_next = dtanh @ self.Whh.T

        # Gradient clipping to prevent exploding gradients
        for grad in [dWxh, dWhh, dWhy, dbh, dby]:
            np.clip(grad, -5, 5, out=grad)

        # Update parameters
        self.Wxh -= self.learning_rate * dWxh
        self.Whh -= self.learning_rate * dWhh
        self.Why -= self.learning_rate * dWhy
        self.bh -= self.learning_rate * dbh
        self.by -= self.learning_rate * dby

        return loss

    def train(self, X_train, y_train, epochs=100, batch_size=32, verbose=True):
        """
        Train the RNN on sequential data using mini-batches.

        Args:
            X_train: Training data (num_samples, sequence_length, input_size).
            y_train: Labels as integers (num_samples,).
            epochs: Number of training epochs.
            batch_size: Number of samples per mini-batch.
            verbose: Whether to print loss during training.
        """
        num_classes = int(np.max(y_train)) + 1
        num_samples = X_train.shape[0]
        # One-hot encode labels
        all_labels = np.eye(num_classes)[y_train.astype(int)]

        for epoch in range(epochs):
            # Shuffle data each epoch
            perm = np.random.permutation(num_samples)
            X_shuffled = X_train[perm]
            y_shuffled = y_train[perm]
            labels_shuffled = all_labels[perm]

            epoch_loss = 0.0
            num_batches = 0

            for start in range(0, num_samples, batch_size):
                end = min(start + batch_size, num_samples)
                X_batch = X_shuffled[start:end].transpose(1, 0, 2)
                labels_batch = labels_shuffled[start:end]

                output, hidden_states = self.forward(X_batch)
                loss = self.backward(X_batch, hidden_states, output, labels_batch)
                epoch_loss += loss
                num_batches += 1

            if verbose and (epoch + 1) % 20 == 0:
                predictions = self.predict(X_train, batch_size)
                accuracy = np.mean(predictions == y_train) * 100
                avg_loss = epoch_loss / num_batches
                print(
                    f"Epoch {epoch + 1}/{epochs} - "
                    f"Loss: {avg_loss:.4f} - Accuracy: {accuracy:.1f}%"
                )

    def predict(self, X, batch_size=32):
        """
        Predict class labels for input sequences.

        Args:
            X: Input data (num_samples, sequence_length, input_size).
            batch_size: Number of samples per forward pass.

        Returns:
            Predicted class labels (num_samples,).
        """
        all_preds = []
        for start in range(0, X.shape[0], batch_size):
            end = min(start + batch_size, X.shape[0])
            inputs = X[start:end].transpose(1, 0, 2)
            output, _ = self.forward(inputs)
            all_preds.append(np.argmax(output, axis=1))
        return np.concatenate(all_preds)


def generate_synthetic_data(num_samples=500, seq_length=10, input_size=3):
    """
    Generate synthetic sequential data for binary classification.
    Class 0: sequences where values tend to increase over time.
    Class 1: sequences where values tend to decrease over time.
    """
    X = np.zeros((num_samples, seq_length, input_size))
    y = np.zeros(num_samples)

    for i in range(num_samples):
        if i < num_samples // 2:
            # Increasing trend
            for t in range(seq_length):
                X[i, t] = np.random.randn(input_size) * 0.5 + t * 0.3
            y[i] = 0
        else:
            # Decreasing trend
            for t in range(seq_length):
                X[i, t] = np.random.randn(input_size) * 0.5 - t * 0.3
            y[i] = 1

    # Shuffle
    indices = np.random.permutation(num_samples)
    return X[indices], y[indices]


if __name__ == "__main__":
    np.random.seed(42)
    # Suppress expected NumPy warnings from early gradient steps
    np.seterr(over="ignore", invalid="ignore", divide="ignore")

    # Generate data
    X, y = generate_synthetic_data(num_samples=500, seq_length=10, input_size=3)

    # Split into train and test
    split = int(0.8 * len(X))
    X_train, X_test = X[:split], X[split:]
    y_train, y_test = y[:split], y[split:]

    # Normalize
    mean = X_train.mean()
    std = X_train.std()
    X_train = (X_train - mean) / std
    X_test = (X_test - mean) / std

    # Create and train the RNN
    rnn = RNN(input_size=3, hidden_size=16, output_size=2, learning_rate=0.005)
    print("Training RNN on synthetic sequential data...\n")
    rnn.train(X_train, y_train, epochs=200)

    # Evaluate
    predictions = rnn.predict(X_test)
    test_accuracy = np.mean(predictions == y_test) * 100
    print(f"\nTest Accuracy: {test_accuracy:.1f}%")
