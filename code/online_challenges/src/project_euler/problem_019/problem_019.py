import datetime


def compute():
	ans = 0
	for y in range(1901, 2001):
		for m in range(1, 13):
			if datetime.date(y, m, 1).weekday() == 6:
				ans += 1
	return str(ans)


if __name__ == "__main__":
	print(compute())
