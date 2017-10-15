"""
SIMPLE LAPINDROME TESTER IN PYTHON 2.7
"""
val = str(raw_input())   # getting user input
length = len(val)  # calculating the length
mid = length / 2   # getting mid point in order set splicings
breaker = mid     # mid break / slice point for even number
if not (length % 2 == 0):
    breaker += 1     #   mid break / slice point for odd number

# slicinng strings
first = val[0:mid]
second = val[breaker:length]

# sorting strings and assigning where first - left split and second -  right split
first = "".join(sorted(first))
second = "".join(sorted(second))

#  if left split is same as right split then number is lapindrome
if first == second:
    print "LAPINDROME"
else:
    print "NOT A LAPINDROME"
