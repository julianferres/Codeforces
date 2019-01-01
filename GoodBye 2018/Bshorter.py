def Bshorter():

	n = int(input())

	x = 0
	y = 0

	for i in range(2*n):

		xy_in = input().split()

		x+= int(xy_in[0])
		y+= int(xy_in[1])

	print("{} {}".format(x//n,y//n))

Bshorter()


