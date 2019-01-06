def D2new():

	n = int(input())

	if(n==1):
		print("YES")
		return
	
	bricks = input().split()
	bricks = [int(x) for x in bricks]

	stack = []
	m = min(bricks)
	M = max(bricks)

	for i in range(n):

		if(not len(stack)):
			stack.append(bricks[i])
			continue

		if(stack[-1] == bricks[i]):
			stack.pop()
			continue

		if(stack[-1]== m):
			print("NO")
			return

		stack.append(bricks[i])


	if(len(stack)==0):
		print("YES")
		return
	if(len(stack)==1):
		print("YES") if stack[0]==M else print("NO")
		return

	print("NO")


		
D2new()
