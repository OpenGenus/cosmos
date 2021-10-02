# Calculation of PI using Leibniz formula

# Function to calcultae PI using Leibniz
def leibniz(n):
    sum = 0
    for i in range(n):
        term = (-1) ** i /(2*i+1)
        sum = sum + term
    return sum * 4

# Reading number of terms to be considered in Leibniz formula
terms = int(input("Enter number of terms (More number of terms gives accurate value): "))

# Function call
pi = leibniz(terms)

# Output result
print("Pi = ", pi)