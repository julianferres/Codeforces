def C():

	n , x , y = map(int, input().split())
	doors = [int(x) for x in input().split()]


	if(y >= x):
		ans = 0
		for d in doors:
			if(d<=x): ans+=1

		print((ans+1)//2)
		return


	print(n)

C()