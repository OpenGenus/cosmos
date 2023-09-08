def convert0To5(num):
    toRet = str(num).replace("0", "5")
    return int(toRet)

def main():
	num = 10120
	print(convert0To5(num))

if __name__ == "__main__":
	main()
