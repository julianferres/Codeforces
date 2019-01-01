def A():

	n = int(input())

	for i in range(n):

		lr = input().split()
		l , r = int(lr[0]) , int(lr[1])

		print(" ".join([str(l),str(2*l)]))

A()