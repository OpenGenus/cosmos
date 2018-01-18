sumOfSquares = 0
squareOfSum = 0

for n in range(1, 101):
    sumOfSquares += (n * n)
    squareOfSum += n

squareOfSum *= squareOfSum

print(squareOfSum - sumOfSquares)
