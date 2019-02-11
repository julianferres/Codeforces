def D():

	n = int(input())

	parents = {}
	

	inp = input().split()
	inp = [int(x) for x in inp]

	for i in range(n-1):
		parents[i+2] = inp[i]

	leafs = set()
	
	for i in range(1,n+1):
		if i not in parents.values():
			leafs.add(i)

	sums = input().split()
	sums = {x+1 : int(sums[x]) for x in range(n)}

	#Chequeo si es posible primero y voy completando las a_i

	a = {i:100000000000000000 for i in sums}
	a[1] = sums[1]

	for act in leafs:

		if(sums[act]==-1): 
			a[act]=0

		while(parents[act] in parents):

			#Primera pasada para rellenar -1

			if(sums[parents[act]]==-1):
				a[parents[act]] = min(a[parents[act]],sums[act]-sums[parents[parents[act]]])
			
			if(a[parents[act]]<0):
				print(-1)
				return
				
			act = parents[act]
			continue

			

			if(sums[act]==-1):
				act = parents[act]

			else:
				a[act] = sums[act]-sums[parents[parents[act]]]-a[parents[act]]
				if(a[act]<0):
					print(-1)
					return
				act = parents[act]

	print(sum(a.values()))


D()