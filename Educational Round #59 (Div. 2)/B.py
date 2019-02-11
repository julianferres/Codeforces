def B():
	n = int(input())
	for _ in range(n):
		k , x = map( int , input().split() )
		print(x+9*(k-1))
B()