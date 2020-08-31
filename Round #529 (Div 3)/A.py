def A():

	n = int(input())
	s = input()

	triang = lambda x: int(x*(x+1)/2)

	r = ""

	i = 0
	while(triang(i)<n):
		r+=s[triang(i)]
		i+=1

	print(r)

A()