import math

def C():

	T = int(input())
	for i in range(T):
		angle = int(input())

		d = math.gcd(180,angle)

		if(angle + d >= 180):
			print(2*180// d)
			continue

		print(180//d)

C()

