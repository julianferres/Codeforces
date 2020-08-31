from heapq import *
n , k = map(int,input().split())
a = [int(x) for x in input().split()]

dif = [a[i+1]-a[i] for i in range(n-1)]
dif.append(0)
ans = sum(dif)
heap = []
for i in dif:
	heappush(heap,-i)

for _ in range(k-1):
	ans-= -(heappop(heap))
print(ans)
