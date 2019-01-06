def A():

	table = input()

	hand = input().split()

	numero , palo = table[0] , table[1]


	for h in hand:

		if (h[0]== numero):

			print("YES")
			return

		if(h[1]==palo):
			print("YES")
			return


	print("NO")

A()