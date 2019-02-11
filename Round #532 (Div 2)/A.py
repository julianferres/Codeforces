def A():

	n , k = map( int , input().split())
	tabs = [int(x) for x in input().split()]

	dif = -float('inf')

	for b in range(k):
		aux = sum(tabs)
		i = 0
		while(b+i*k < n):
			if(tabs[b+i*k]==1): aux-=1
			else: aux+=1
			i+=1
		dif = max(abs(aux) , dif)

	print(dif)

A()