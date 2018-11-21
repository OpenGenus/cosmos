def compute():
	ans = 0
	for n in range(2, 10):
		for i in range(1, 10**(9 // n)):
			s = "".join(str(i * j) for j in range(1, n + 1))
			if "".join(sorted(s)) == "123456789":
				ans = max(int(s), ans)
	return str(ans)


if __name__ == "__main__":
	print(compute())
