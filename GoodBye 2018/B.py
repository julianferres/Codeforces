def B():

	n = int(input())

	obeliscs = set()
	clues = set()

	for i in range(n):
		xy = input().split()
		xi , yi = int(xy[0]) , int(xy[1])

		obeliscs.add((xi,yi))

	for i in range(n):
		xy = input().split()
		xi , yi = int(xy[0]) , int(xy[1])
		clues.add((xi,yi))

	treasure = 0
	clue_sample = list(clues)[0]

	for o in obeliscs:
		treasure = (o[0]+clue_sample[0],o[1]+clue_sample[1])
		for o2 in obeliscs:
			if( (treasure[0]-o2[0],treasure[1]-o2[1]) not in clues):
				treasure = None
				break

		if(treasure):			
			print( " ".join( ( str(treasure[0]), str(treasure[1]) ) ) )
			return

B()