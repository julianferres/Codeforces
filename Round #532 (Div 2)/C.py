import math

def C():

	n , r = map( int, input().split() )

	c = math.cos(math.pi*(n-2)/(2*n))

	print((c*r)/(1-c))

C()