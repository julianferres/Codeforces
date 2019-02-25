def E():
	n = int(input())
	c = [int(x) for x in input().split()]
	t = [int(x) for x in input().split()]
	
	c_p = sorted([c[i+1]-c[i] for i in range(n-1)])
	t_p = sorted([t[i+1]-t[i] for i in range(n-1)])

	if(c_p!=t_p):
		print("No")
		return

	print("Yes") if(c[0]==t[0]) else print("No")
E()

