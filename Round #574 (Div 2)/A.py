n, k = map(int,input().split())
a = []
for _ in range(n):
	a.append(int(input()))

from collections import Counter
from math import ceil
ans = 0
c = Counter(a)

for i in c:
	ans+=c[i]//2

print(ans+ceil(n/2))
