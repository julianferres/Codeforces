def A():

	alphabet = "abcdefghijklmnopqrstuvwxyz"

	t = int(input())

	s = []
	for i in range(t):

		nk = input().split()
		n , k = int(nk[0]) , int(nk[1])

		s_i = ""

		for i in range(n): s_i+= alphabet[i%k]

		s.append(s_i)

	for s_i in s: print(s_i)

A()