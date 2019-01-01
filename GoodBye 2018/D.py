def D():
	mod = 998244353
	n = int(input())
	x = n
	for i in range(2,n+1):
		x-=1
		x=x*i%mod
	print(x)

D()