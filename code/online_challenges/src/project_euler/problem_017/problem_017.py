num1 = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen',
        'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']

num2 = ['twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']

sum = 0
for x in range(0, 9):
    sum += len(num1[x])
    for y in range(0, 8):
        sum += len(num1[x] + num2[y])
        for z in range(0, 9):
            sum += len(num1[x] + 'hundred' + 'and' + num2[y] + num1[z])
        sum += len(num1[x] + 'hundred' + 'and' + num2[y])

# 10 ~ 19
for a in range(9, 19):
    sum += len(num1[a])

# 20, 30, 40
for b in range(0, 8):
    sum += len(num2[b])

# 100, 200, 300
for c in range(0, 9):
    sum += len(num1[c] + 'hundred')
    for d in range(0, 19):
        sum += len(num1[c] + 'hundred' + 'and' + num1[d])

print(sum + 11)
