import heapq
def B():
	n , m , k = map( int , input().split())
	b = [int(x) for x in input().split()]
	dist = []
	for x in range(n-1):
		heapq.heappush(dist,b[x+1]-b[x]-1)
	ans = n
	for i in range(n-k):
		ans+=heapq.heappop(dist)
	
	print(ans)
B()
