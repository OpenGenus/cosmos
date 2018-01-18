def main(size):
  last, actual = 1, 1
  index = 2
  
  while actual < size:
    last, actual = actual, last + actual
    index += 1
    
  print(index)
  
main(10**999)
