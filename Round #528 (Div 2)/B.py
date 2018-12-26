def B():

	a = input()
	a = a.split()
	
	n,k = int(a[0]), int(a[1])

	minimo_x = 10000000000000000000000000000000  
	
	for r in range(1,min(n+1,k)):

		if(not n%r): # r | n
			minimo_x = min((n//r)*k+r ,minimo_x)


	print(minimo_x)


B()