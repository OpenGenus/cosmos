# Recursive Factorial

This program shows how we can calculate any integer factorial recursively. A factorial is defined 
as $n! = (n) \cdot (n-1) \cdot (n-2) \cdots (2) \cdot (1)$. So, we can rewrite this as $n! = (n) \cdot (n-1)!$ 
with base cases of $1! = 1$ and $0! = 1$. This is our recursive definition and is how we implement 
the code.

## Features

- **Factorial Calculation**: The program calculates the factorial of a non-negative integer.
- **Exception Handling**: Throws an exception when trying to compute the factorial of a negative number.\

## Getting Started

### Running the Program

1. Clone this repository to your local machine.
2. Compile and run the `Factorial` class.

### Warning

Be aware that factorials grow extremely quickly. So, there is a limit to how large the input 
$n$ can be without causing overflow, leading to an incorrect answer.
