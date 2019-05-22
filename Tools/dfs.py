def rec_dfs(graph , node , visited):

	if node not in visited:
		visited.append(node)

		for ady in graph[node]:
			dfs_rec(graph , ady , visited)


def dfs(graph , node):
	visited = []

	rec_dfs(graph , node , visited)
	print(visited)



dfs({1:[2,3],2:[4],3:[4],4:[]} , 1)
