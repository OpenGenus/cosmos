def main():
	prob = []
	for i in range(15):
		prob.append([int(x) for x in input().strip().split()])
	for i in range(13,-1,-1):
		for j in range(len(prob[i])):
			prob[i][j] += max(prob[i + 1][j],prob[i + 1][j + 1])
	print (prob[0][0])

if __name__ == '__main__':
	main()
