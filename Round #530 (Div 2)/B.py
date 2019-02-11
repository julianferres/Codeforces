def B():

	n = int(input())

	for i in range(1, n+1	):
		if(i**2>=n):
			print(2*i)
			return

		if(i*(i+1)>=n):
			print(2*i+1)
			return

B()