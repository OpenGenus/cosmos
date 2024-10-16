# Dynamic Programming solution to friends pairing problem in Python3
# Contributed by Santosh Vasisht

# Given n friends, each one can remain single or can be paired up with some other friend.
# Each friend can be paired only once.
# Find out the total number of ways in which friends can remain single or can be paired up.

def countFriendsPairings(n: int) -> int:
    table = [0] * (n+1)
    
    # Filling the table recursively in bottom-up manner
    for i in range(n+1):
        if i <= 2:
            table[i] = i
        else:
            table[i] = table[i-1] + (i-1) * table[i-2]
    
    return table[n]

#Driver Code
if __name__ == '__main__':
    n = 7
    print(countFriendsPairings(n))