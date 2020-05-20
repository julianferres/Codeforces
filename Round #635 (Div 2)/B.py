t = int(input())
for _ in range(t):
	x,n,m = map(int, input().split())
	
	for i in range(n):
		if(x>=20):
			x = x//2+10
	for i in range(m):
		x -= 10
	
	print("YES") if x<=0 else print("NO")
	
