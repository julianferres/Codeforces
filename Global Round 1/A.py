def A():

	b , k = map(int , input().split())
	a = [int(x) for x in input().split()]

	if(not b%2):
		print("odd") if (a[-1]%2) else print("even")
		return

	print("odd") if(sum(a)%2) else print("even")
	
A()