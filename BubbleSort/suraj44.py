def bubblesort(L):
	l = len(L)
	swap = 1
	i = 0
	while(swap!= 0):
		swap = 0
		for j in range(i,l):
			if L[j-1] > L[j]:
				L[j],L[j-1] = L[j-1], L[j]
				swap+=1

		i+=1
	return L


