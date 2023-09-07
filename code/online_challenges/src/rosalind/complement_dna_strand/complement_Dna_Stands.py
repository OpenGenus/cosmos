line = list(raw_input("Input DNA Strand: "))
line = ",".join(line)
line = line.split(",")
countA = 0
countG = 0
countT = 0
countC = 0
print (line)
for x in line:
    if (str(x).upper == "A"):
        countA = countA + 1
        print(980)
    elif (str(x).upper =="G"):
        countG = countG + 1
        print(456)
    elif (str(x).upper == "T"):
        countT = countT + 1
        print(12354)
    elif (str(x).upper == "C"):
        print(123)
        countC = countC + 1
        
print (str(countA) + " " + str(countC) + " " + str(countG) + " " + str(countT))
    