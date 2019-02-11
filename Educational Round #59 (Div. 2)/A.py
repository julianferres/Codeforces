def A():

	q = int(input())

	for i in range(q):
		ni = int(input())
		s = input()

		if(ni==2 and s[0]>=s[-1]):
			print("NO")
		else:
			print("YES")
			print(2)
			print(s[0],s[1:])

A()