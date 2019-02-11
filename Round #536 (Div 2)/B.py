n , m = map( int , input().split() )
a = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]

s = [(i,c[i]) for i in range(n)]
s = sorted(s , key = lambda x:(x[1],x[0]))

cheapest = 0
for _ in range(m):
	cost = 0
	t , d = map(int , input().split())
	minimo = min(a[t-1],d)
	cost+= minimo*c[t-1]
	a[t-1]-=minimo
	d-=minimo
		
	while(d>0 and cheapest < n): #O salí, o agote productos
		i_min = s[cheapest][0]
		cost_min = s[cheapest][1]

		minimo = min(a[i_min] , d)

		a[i_min]-= minimo
		cost+= cost_min*minimo
		d-= minimo

		if(a[i_min]==0):
			cheapest+=1
	if(d == 0):
		print(cost)	
	else:
		print(0)