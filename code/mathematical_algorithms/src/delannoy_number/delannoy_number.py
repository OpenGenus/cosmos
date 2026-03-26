# Function to generate the Delannoy number for coordinates (n, m)
def DelannoyGenerator(n, m):
    
    # Base Case:
    # If either n or m is 0, there is only one path to reach that point
    # because we can only move in one direction (either horizontal or vertical)
    if n == 0 or m == 0:
        d = 1
    
    else:
        # Recursive Case:
        # The Delannoy number is calculated as the sum of:
        # 1. Paths coming from (n-1, m)  -> move vertically
        # 2. Paths coming from (n, m-1)  -> move horizontally
        # 3. Paths coming from (n-1, m-1) -> move diagonally
        d = (
            DelannoyGenerator(n - 1, m) +
            DelannoyGenerator(n, m - 1) +
            DelannoyGenerator(n - 1, m - 1)
        )

    # Return the calculated Delannoy number
    return d


# Take input from the user for coordinates n and m
n = int(input("Provide the 'n' value: "))
m = int(input("Provide the 'm' value: "))

# Print the computed Delannoy number
print(f"The delannoy number is: {DelannoyGenerator(n, m)}")
