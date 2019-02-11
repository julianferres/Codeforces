def A():

	n = int(input())
	a = [int(x) for x in input().split()]

	cost = float('inf')
	ans = min(a)

	for t in range(min(a),max(a)+1):
		aux = 0
		for x in a:
			if( abs(x-t)<=1 ):
				continue

			aux+= abs(x-t)-1

		if(aux < cost):
			ans = t
			cost = aux

	print("{} {}".format(ans , cost))

A()