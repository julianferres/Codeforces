def D():

	n = int(input())
	neighbours = [None] #Asi puedo manejar numero de personas como index
	for i in range(n):
		neighbours.append([int(x) for x in input().split()])

	visited = set()
	ans = [None,1]
	visited.add(1)

	a , b = neighbours[1][0] , neighbours[1][1]

	if(b in neighbours[a]):
		ans+=[a,b]
	else:
		ans+=[b,a]

	visited.add(a)
	visited.add(b)

	for i in range(1,n):
		person = ans[i]
		if(neighbours[person][0] not in visited):
			ans.append(neighbours[person][0])
			visited.add(neighbours[person][0])
		if(neighbours[person][1] not in visited):
			ans.append(neighbours[person][1])
			visited.add(neighbours[person][1])

	ans = ans[1:]
	ans = [str(x) for x in ans]
	print(" ".join(ans))

D()	