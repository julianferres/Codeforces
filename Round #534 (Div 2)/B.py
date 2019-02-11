def B():

	s = input()
	stack = []
	counter = 0

	for x in s:
		if(not len(stack)):
			stack.append(x)
		elif(stack[-1]==x):
			stack.pop()
			counter+=1
		else:
			stack.append(x)

	print("Yes") if(counter%2) else print("No")

B()