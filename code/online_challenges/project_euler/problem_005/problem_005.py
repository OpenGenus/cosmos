def find_multiple(number, current):
    step = current
    flag = False
    while not flag:
        for i in range(2, number + 1):
            flag = True
            if current % i != 0:
                flag = False
                current += step
                break
            continue
    return current

holder = [1]
fin_numb = 20  # change only this number
for i in range(2, fin_numb + 1):
    holder.append(find_multiple(i, holder[-1]))

answer = holder[-1]
print (answer)