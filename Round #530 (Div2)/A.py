def A():

	snowball = input().split()
	stone1 = input().split()
	stone2 = input().split()


	weight , height = int(snowball[0]) , int(snowball[1])
	stone1_w , stone1_h = int(stone1[0]) , int(stone1[1])
	stone2_w , stone2_h = int(stone2[0]) , int(stone2[1])


	for h in range( height ,0,-1):

		weight+= h

		if( h == stone1_h ): 
			weight = max(0, weight-stone1_w)

		if(h == stone2_h):
			weight = max(0 , weight-stone2_w)




	print(weight)

A()