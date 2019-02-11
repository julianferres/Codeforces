def B():
	n = int(input())
	s = [int(x) for x in input().split()]

	x = max(s)
	for d in range(1,x+1):
		if(x%d ==0):
			s.remove(d)
	y = max(s)
	
	print(x,y)

B()