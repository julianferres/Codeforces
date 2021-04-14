from math import ceil
r, x, y = map(int, input().split())

d2 = x**2 + y**2
d = d2**0.5

if(d == r):
	print(1)
elif(d != r and d <= 2*r):
	print(2)
else:
	print(ceil(d/r))

