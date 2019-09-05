def solve():
	n = int(input())
	s = input()
	op = 0
	cl = 0
	stack = []
	for i in s:
		op += int(i=='(')
		cl += int(i==')')
		if len(stack)==0:
			stack.append(i)
		elif stack[-1]=='(' and i==')':
			stack.pop()
		else:
			stack.append(i)

	if(len(stack)<=2 and op==cl):
		print("Yes")
		return
	print("No")


solve()