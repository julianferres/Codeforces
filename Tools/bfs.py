from collections import deque

empty_queue = lambda q: len(q)==0

def bfs(graph, root, visited = set()):
    travel = []
    q = deque([])

    q.append(root)
    visited.add(root)

    while( not empty_queue(q) ):

        actNode = q.popleft() #Dequeue
        travel.append(actNode)
        for adyacent in graph[actNode]:
            if(adyacent not in visited):
                q.append(adyacent) #Enqueue adyacent
                visited.add(adyacent)

    return travel
