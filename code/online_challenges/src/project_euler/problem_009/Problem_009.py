import sys
for i in range(1,1000):
    for j in range (1,1000):
        for k in range(1,1000):
            if (i*i) + (j*j) == (k*k) and (i + j + k) == 1000:
                print(i*j*k)
                sys.exit(0)
            
