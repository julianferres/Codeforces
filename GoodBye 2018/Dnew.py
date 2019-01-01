import math

def variations(n,k,nfactorial,mod):

	return (nfactorial//math.factorial(n-k))%mod

def D():
	mod = 998244353

	n = int(input())

	ans = n
	for i in range(2,n+1):
		ans -= 1
		ans*= i
		ans %= mod

	print(ans)

D()