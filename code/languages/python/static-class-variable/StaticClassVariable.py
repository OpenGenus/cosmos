# Python program to show that the variables with a value
# assigned in class declaration, are class variables

# Class for different type of Instrument
class Instrument:
   courseoffered = 'yes'                  # Class Variable
   def __init__(self,price,tax):
       self.Instrumentname = Instrumentname      # Instance Variable
       self.count = count           # Instance Variable

# Objects of CSStudent class
a = Instrument('Guitar', 1)
b = Instrument('piaono', 2)

print(a.courseoffered)  # prints "yes"
print(b.courseoffered)  # prints "yes"
print(a.Instrumentname)    # prints "Guitar"
print(b.Instrumentname)    # prints "Piaono"
print(a.count)    # prints "1"
print(b.count)    # prints "2"

# Class variables can be accessed using class
# name also
print(Instrument.courseoffered) # prints "yes"

# Now if we change the courseoffered for just a it won't be changed for b
a.courseoffered = 'No'
print(a.courseoffered) # prints 'no'
print(b.courseoffered) # prints 'yes'

# To change the courseoffered for all instances of the class we can change it
# directly from the class
instrument.courseoffered = 'yes'

print(a.courseoffered) # prints 'yes'
print(b.courseoffered) # prints 'no'
