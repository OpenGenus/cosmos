# Function to count how many times a value x appears in a tuple
def countX(tup, x): 
    count = 0                 # Initialize a counter variable to 0
    
    # Loop through each element in the tuple
    for ele in tup: 
        # Check if the current element is equal to x
        if (ele == x): 
            count = count + 1 # If yes, increase the counter by 1
            
    return count              # Return the final count


# Driver Code (main part of the program)

# Tuple containing numbers
tup = (10, 8, 5, 2, 10, 15, 10, 8, 5, 8, 8, 2) 

# Values whose frequency we want to find
enq = 4
enq1 = 10
enq2 = 8

# Calling the function and printing results
print(countX(tup, enq))   # Count how many times 4 appears
print(countX(tup, enq1))  # Count how many times 10 appears
print(countX(tup, enq2))  # Count how many times 8 appears
