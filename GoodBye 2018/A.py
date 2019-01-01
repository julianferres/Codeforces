def A():

	ybr = input().split()
	y , b , r = int(ybr[0]) , int(ybr[1]) , int(ybr[2])

	a = min(y, b-1, r-2)
	print(3*a+3)

A()
