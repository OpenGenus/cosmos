# Part of Cosmos by OpenGenus Foundation

def collatz_conjecture_sequence(n):
    print(n)
    
    while n != 1:
        
        if n%2==0:
            n = n/2
        
        else:
            n = (3*n) + 1
        
        print(n)
    
    print(n)

print("Enter a number:")
collatz_conjecture_sequence(int(input()))
