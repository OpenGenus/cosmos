# Recurrent Neural Network (RNN)

A **Recurrent Neural Network (RNN)** is a class of neural networks designed for processing sequential data. Unlike feedforward neural networks, RNNs have connections that form directed cycles, allowing them to maintain a hidden state that captures information from previous time steps.

## How It Works

At each time step *t*, the RNN takes an input **x_t** and the previous hidden state **h_{t-1}** to produce a new hidden state **h_t**:

```
h_t = tanh(x_t * W_xh + h_{t-1} * W_hh + b_h)
y   = softmax(h_T * W_hy + b_y)
```

Where:
- `W_xh` — input-to-hidden weights
- `W_hh` — hidden-to-hidden (recurrent) weights
- `W_hy` — hidden-to-output weights
- `b_h`, `b_y` — biases

The network is trained using **Backpropagation Through Time (BPTT)**, which unrolls the network across time steps and computes gradients for each.

## Key Concepts

- **Vanishing/Exploding Gradients**: As sequences get longer, gradients can shrink or grow exponentially. Gradient clipping helps mitigate exploding gradients.
- **Sequential Memory**: The hidden state acts as a memory that carries information across time steps.
- **Weight Sharing**: The same weights are reused at every time step.

## Applications

- Natural Language Processing (text generation, sentiment analysis)
- Speech recognition
- Time series forecasting
- Machine translation

## Complexity

| Operation | Time Complexity |
|-----------|----------------|
| Forward pass (per time step) | O(H^2 + I*H) |
| BPTT (full sequence) | O(T * (H^2 + I*H)) |

Where *T* = sequence length, *H* = hidden size, *I* = input size.

## Implementation

The included Python implementation (`recurrent_neural_network.py`) builds a vanilla RNN from scratch using only NumPy. It demonstrates:
- Xavier weight initialization
- Forward propagation through time
- BPTT with gradient clipping
- Training on synthetic sequential data

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a>
</p>
