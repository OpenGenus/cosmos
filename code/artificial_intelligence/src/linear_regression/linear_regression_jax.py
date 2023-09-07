import numpy as np
import jax.numpy as jnp
import jax


inputs = np.array([[73, 67, 43], 
                   [91, 88, 64], 
                   [87, 134, 58], 
                   [102, 43, 37], 
                   [69, 96, 70]], dtype='float32')

targets = np.array([[56, 70], 
                    [81, 101], 
                    [119, 133], 
                    [22, 37], 
                    [103, 119]], dtype='float32')

@jax.jit
def predict(x: np.ndarray, w: np.ndarray, b: np.ndarray):
    return x @ w.T + b


@jax.jit
def mse(a, b):
    diff = a - b
    return np.sum(diff**2) / diff.size


@jax.jit
def loss_fn(w: np.ndarray, b: np.ndarray):
    preds = predict(inputs, w, b)
    loss = mse(preds, targets)
    return loss


def linear(in_features: int, out_features: int, learning_rate=1e-4):
    weight = np.random.normal(size=(out_features, in_features)).astype('float32')
    bias = np.random.normal(size=(out_features)).astype('float32')
    
    for epoch in range(100):
        dy_dw, dy_db = jax.jacfwd(loss_fn, (0, 1))(weight, bias)
        weight = weight - learning_rate * dy_dw
        bias = bias - learning_rate * dy_db
        y = loss_fn(weight, bias)
        print(f'{epoch} => {y}')

    print(f'predict: \n {predict(inputs, weight, bias)}')
    print(f'targets: \n {targets}')


if __name__ == "__main__":
    linear(3, 2)