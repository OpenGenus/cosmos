fat = 1
fat2 = 1

for x in range(40, 0, -1):
    if x <= 20:
        fat2 *= x
    else:
        fat *= x

print(fat / fat2)