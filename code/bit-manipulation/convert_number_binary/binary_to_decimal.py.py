# Python Program - Convert Binary to Decimal
		
while True:
	print("Enter 'x' for exit.")
	binary = raw_input("Enter number in Binary Format: ")
	if binary == 'x':
		break
	else:
		decimal = int(binary, 2)
		print(binary,"in Decimal =",decimal,"\n")