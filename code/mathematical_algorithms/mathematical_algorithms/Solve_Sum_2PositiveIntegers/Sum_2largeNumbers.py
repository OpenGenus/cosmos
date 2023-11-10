a = input("Enter 1st number: ")
b = input("Enter 2nd number: ")
 
if (a.isdigit() and b.isdigit()):
    m=0
    sum=""
    n1 = list(a)
    n2 = list(b)
    while True:
       #Take far right digits
       digit1 = n1.pop() if len(n1) > 0 else None
       digit2 = n2.pop() if len(n2) > 0 else None
       #no more digit to take escape
       if ( digit1 == None and digit2 == None):
           break
       #still a digit in sencond 
       elif digit1 == None:
           sum_digit = int(digit2) + m
       #still a digit in first
       elif digit2 == None:
           sum_digit = int(digit1) + m
       # both have a digit
       else:
           sum_digit = int(digit1) + int(digit2) + m
       # remember 1 if greater than 10    
       m = sum_digit//10
       # add the digit to  sum string 
       sum = str(sum_digit%10) + sum
    # make sure add 1 to sum string if needs
    sum = (str(m) if m==1 else "") + sum
    # output
    print(f"Sum is {sum}")       

