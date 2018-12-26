def D():
	ns = input().split()
	n , s = int(ns[0]) , int(ns[1])
	
	degrees = [0 for i in range(n)]

	for i in range(n-1):
		arista = input().split()
		degrees[int(arista[0])-1]+=1
		degrees[int(arista[1])-1]+=1

	leaf_count = 0
	for i in range(n):
		if (degrees[i]==1): leaf_count+=1

	print(2*s/leaf_count)

D()