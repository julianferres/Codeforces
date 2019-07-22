def c():

	n = int(input())
	h1 = [int(x) for x in input().split()]
	h2 = [int(x) for x in input().split()]

	if(n==1):
		print(max(h1[0],h2[0]))
		return

	dp1 = [0]*n
	dp2 = [0]*n
	dp1[0], dp2[0] = h1[0], h2[0]
	dp1[1] = h2[0]+h1[1]
	dp2[1] = h2[1]+h1[0]
	
	for i in range(2,n):
		dp1[i] = h1[i] + max(dp2[i-1],dp2[i-2])
		dp2[i] = h2[i] + max(dp1[i-1],dp1[i-2])
	print(max(dp1[-1],dp2[-1]))
	return 0

c()
