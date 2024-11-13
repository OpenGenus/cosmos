import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import SimpleRNN, Dense

# Generate dummy sequential data
def generate_data(seq_length=50, total_sequences=1000):
    X = []
    y = []
    for _ in range(total_sequences):
        # Create random sequences of length 'seq_length'
        sequence = np.random.rand(seq_length)
        target = np.sum(sequence)  # The target could be the sum of the sequence
        X.append(sequence)
        y.append(target)
    return np.array(X), np.array(y)

# Prepare the dataset
seq_length = 10
X, y = generate_data(seq_length=seq_length)

# Reshape input to be [samples, time steps, features] for RNN input
X = X.reshape((X.shape[0], seq_length, 1))

# Build the RNN model
model = Sequential()
model.add(SimpleRNN(50, activation='relu', input_shape=(seq_length, 1)))
model.add(Dense(1))

# Compile the model
model.compile(optimizer='adam', loss='mse')

# Train the model
model.fit(X, y, epochs=10, batch_size=32)

# Predict on new data
test_data = np.random.rand(1, seq_length).reshape(1, seq_length, 1)
prediction = model.predict(test_data)

print(f"Prediction: {prediction}")
