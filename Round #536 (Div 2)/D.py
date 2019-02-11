from heapq import *

n , m = map( int , input().split() )
graph = {}

for _ in range(m):
    a , b = map( int , input().split() )
    graph.setdefault(a, set()).add(b)
    graph.setdefault(b, set()).add(a)

ans = []
visited = set()
heap = [1]

while heap:
    v = heappop(heap)
    if v in visited:
        continue
    visited.add(v)
    ans.append(v)
    for neighbour in graph[v]:
        heappush(heap, neighbour)

print(*ans)

