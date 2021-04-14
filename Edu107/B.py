from math import gcd

def test():
	a, b, c = map(int, input().split())
	assert(gcd(10**a, 10**b + 10**c) == 10**c+1)
	print(10**a, 10**b + 10**c)

t = int(input())
for i in range(t):
	test()

