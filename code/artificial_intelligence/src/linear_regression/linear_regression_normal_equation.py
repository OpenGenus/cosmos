import numpy as np

# Implement linear regression using the closed form equation
# For optimal weights W, input matrix X and target matrix y, 
# W = ((XT.X)^-1).(XT.y)  : XT is transpose of X
# Refer: https://www.geeksforgeeks.org/ml-normal-equation-in-linear-regression/


def generate_data(m, n):
    """
    Generates features and target dataset for m instances and n features
    X and y are approximately linear
    """

    # Generating a dataset with m instances and n features
    X = 42 * np.random.rand(m, n)

    # Creating y as a function of X along with some noise (y = a * X + b + noise)
    y = np.random.randint(0, 100) * X + np.random.randint(0, 100) + np.random.rand(m, n)

    return X, y


def normal_equation(X, y):
    """
    Takes in (input, target) matrices
    Outputs coefficients for line of best fit using normal equation
    """

    # X.shape is m, n here, we don't need n
    m, _ = X.shape

    # Add x0 = 1 to each term to accommodate bias
    # Our theta vector will now have bias term
    X_b = np.c_[np.ones((m, 1)), X]

    # We will use NumPy's Linear Algebra module (np.linalg)
    # array.T gives transpose of the array
    # array1.dot(array2) is used to calculate the dot products
    theta = np.linalg.inv(X_b.T.dot(X_b)).dot(X_b.T).dot(y)

    return theta


def calculate_rmse(y_pred, y):
    """Calculate root mean squared error given truth y and predictions y_pred"""

    return np.sqrt(np.mean((y_pred - y) ** 2))


def main():

    # Edit here if you want different dimensions for input matrix
    m, n = 100, 2

    X, y = generate_data(m, n)

    # Print the first few instances
    print(f"First few rows of input matrix:\n{X[:min(m, 4)]}")

    theta = normal_equation(X, y)

    # Calculate predictions by taking dot product of X and theta
    # Add x0 = 1 to each instance to accommodate bias term
    X_b = np.c_[np.ones((m, 1)), X]
    y_pred = X_b.dot(theta)

    # Get and print the RMSE
    rmse = calculate_rmse(y_pred, y)

    print(f"The root mean squared error achieved is: {rmse}")


if __name__ == "__main__":
    main()