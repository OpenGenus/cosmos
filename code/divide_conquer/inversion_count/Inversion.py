# Part of Cosmos by OpenGenus Foundation

array = []
for i in range(0,100000):
    array.append(int(input()))
count =0

def Sort_Count(array):
    n = len(array)
   
    if n > 1:
        global count
        mid = int(n//2)

        a = array[:mid]
        b = array[mid:]

        Sort_Count(a)
        Sort_Count(b)

        i = j = 0
        for k in range(0,len(array)):
            if a[i]<b[j]:
                array[k] = a[i]
                i+=1
                if i==len(a) and j!=len(b):
                    while j!= len(b):
                        k+=1
                        array[k] = b[j]
                        j+=1
                    break

            elif a[i]>b[j]:
                array[k] = b[j]
                j+=1
                count+=(len(a)-i)
                if j==len(b) and i!=len(a):
                    while i!= len(a):
                        k+=1
                        array[k] = a[i]
                        i+=1
                    break

Sort_Count(array)       
print(count)