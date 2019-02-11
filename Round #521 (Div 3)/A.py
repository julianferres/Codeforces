def A():

	t = int(input())

	for i in range(t):
		query = input().split()
		query = [int(x) for x in query]

		print(-query[1]*(query[-1]//2)+query[0]*((query[-1]+1)//2))

A()