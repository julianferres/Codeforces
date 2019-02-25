import sys

def dfs(graph, node, visited):
    sys.setrecursionlimit(sys.getrecursionlimit() + 1)
    if node not in visited:
        visited.add(node)
        for n in graph[node]:
            dfs(graph,n, visited)
    return visited



def C():
    n = int(input())
    r1 , c1 = map(int, input().split())
    r2 , c2 = map(int, input().split())
    grid = []
    graph = {}
    for _ in range(n):
        grid.append(input())

    for i in range(n):
        for j in range(n):
            if(grid[i][j]=='0'):
                graph[(i,j)]=[]
                if(i>0 and grid[i-1][j]=='0'): graph[(i,j)].append((i-1,j))
                if(i<n-1 and grid[i+1][j]=='0'): graph[(i,j)].append((i+1,j))
                if(j>0 and grid[i][j-1]=='0'): graph[(i,j)].append((i,j-1))
                if(j<n-1 and grid[i][j+1]=='0'): graph[(i,j)].append((i,j+1))

    v1 = dfs(graph,(r1-1,c1-1),set())
    v2 = dfs(graph,(r2-1,c2-1),set())

    d = float('inf')
    for c1 in v1:
        for c2 in v2:
            d = min( d , (c1[0]-c2[0])**2+(c1[1]-c2[1])**2 )
    print(d)

C()
