def main():
	with open('names.txt','r') as f:
		name=f.read().strip('"').split('","')
		total_sum=0
		temp_sum=0
		name.sort()
		for i in range(len(name)):
			for j in name[i]:
				temp_sum += ord(j)-ord('A')+1
			total_sum += (i+1)*temp_sum
			temp_sum= 0
		print(total_sum)


if __name__ == '__main__':
	main()