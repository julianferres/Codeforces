from math import sqrt
n, k = map(int, input().split())

print(n-int(-1.5+sqrt(9/4+2*(k+n))))
