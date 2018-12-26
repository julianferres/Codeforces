def C():

	a = input()
	b = input()
	c = input()

	xa , ya = int(a.split()[0]),int(a.split()[1])
	xb , yb = int(b.split()[0]),int(b.split()[1])
	xc , yc = int(c.split()[0]),int(c.split()[1])

	points = [(xa,ya),(xb,yb),(xc,yc)]
	points.sort()

	plots = []

	dist_x ,dist_y = [abs(xa-xb),abs(xa-xc),abs(xb-xc)] , [abs(ya-yb),abs(ya-yc),abs(yb-yc)]
	print(max(dist_x)+max(dist_y)+1)

	for x in range(points[0][0],points[1][0]+1):

		plots.append("{} {}".format(x , points[0][1]))

	for y in range( min(points[0][1],points[1][1]) , max(points[0][1],points[1][1]) +1):

		if("{} {}".format(points[1][0], y) not in plots): plots.append( "{} {}".format(points[1][0], y) )

	for y in range( min(points[1][1],points[2][1]) , max(points[1][1],points[2][1]) +1 ):

		if("{} {}".format(points[1][0], y) not in plots): plots.append( "{} {}".format(points[1][0], y) )

	for x in range(points[1][0],points[2][0]+1):

		if("{} {}".format(x , points[2][1]) not in plots): plots.append( "{} {}".format(x, points[2][1]) )


	for x in plots: print(x)

C()