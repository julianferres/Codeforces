def D1():

	n = int(input())
	
	bricks = input().split()
	bricks = [int(x)%2 for x in bricks]

	stack = []

	for i in range(n):
		if(not len(stack)): 
			stack.append(bricks[i])
			continue
		if(stack[-1] == bricks[i]): 
			stack.pop()
			continue

		stack.append(bricks[i])


	if(len(stack)<2):
		print("YES")
		return

	print("NO")







D1()