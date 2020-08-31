def C():

	#Ordenar por el extremo izquierdo
	#Tomar el extremo derecho del primero
	#De ahi ir chequeando con cuales se solapa, y mandarlos al 1

	q = int(input())

	for _ in range(q):
		n = int(input())
		tuples = []
		for i in range(n):
			ab = [int(x) for x in input().split()]
			tuples.append((ab[0],ab[1],i))

		tuples.sort()
		sol = ['-1']*n
		r_act = tuples[0][1]

		flag = 0

		for l , r , i in tuples:
			if(flag == 0):
				if l<=r_act:
					r_act = max(r,r_act)
					sol[i] = '1'
				else:
					r_act = r
					sol[i] = '2'
					flag = 1

			if(flag == 1):
				if l<=r_act:
					r_act = max(r,r_act)
					sol[i] = '2'
				else:
					r_act = r
					sol[i] = '1'
					flag = 0


		if( '-1' in sol or '1' not in sol or '2' not in sol):
			print(-1)
			continue

		print(" ".join(sol))







C()