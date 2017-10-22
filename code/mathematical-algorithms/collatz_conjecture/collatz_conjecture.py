def collatz(n):
    seq = [n]
    while n > 1:
        if n%2 == 1:
            n = n*3 + 1
            seq.append(n)
        else:
            n = n/2
            seq.append(n)
    return seq

if __name__ == "__main__" :
    number = input("Enter the number for which collatz sequence is to be displayed : ")
    print collatz(number)
    
