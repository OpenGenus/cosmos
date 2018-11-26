import itertools

def compute():
	for i in itertools.count(1):
		digits = sorted(str(i))
		if all(sorted(str(i * j)) == digits for j in range(2, 7)):
			return str(i)


if __name__ == "__main__":
	print(compute())
