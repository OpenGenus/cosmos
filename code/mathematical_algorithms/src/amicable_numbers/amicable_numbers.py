def ami_check(x, y):
    if x == y:
        return False  # 1
    sum_x = sum(e for e in range(1, x // 2 + 1) if x % e == 0)  # 2
    sum_y = sum(e for e in range(1, y // 2 + 1) if y % e == 0)  # 2
    return sum_x == y and sum_y == x  # 3


if __name__ == "__main__":
    print(ami_check(220, 284))
