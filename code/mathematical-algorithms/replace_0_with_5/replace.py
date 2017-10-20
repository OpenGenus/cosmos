def convert0To5(num):
	toRet = ""
	for n in str(num):
		toRet += "5" if n == "0" else n
	return int(toRet)

def main():
	num = 10120
	print(convert0To5(num))

if __name__ == "__main__":
	main()
