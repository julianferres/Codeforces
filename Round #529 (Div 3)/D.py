def get_index( dic , valor, idx_actual):

	aux = dic[valor	]
	return aux[0] if aux[0]!= idx_actual else aux[1]


def D():

	n = int(input())
	neighbours = []
	for i in range(n):
		neighbours.append([int(x) for x in input().split()])

	dic = {}

	for i in range(1,n+1):
		dic[i] = []

	for i in range(n):
		dic[neighbours[i][0]].append(i)
		dic[neighbours[i][1]].append(i)


	neighbours[0].remove(neighbours[0][1])

	idx_actual = 0
	valor = neighbours[0][0]

	respuesta = [valor]

	for i in range(n-1):
		idx_actual = get_index(dic, valor , idx_actual)
		neighbours[idx_actual].remove(valor)
		
		valor= neighbours[idx_actual][0]
		respuesta.append(valor)


	respuesta = [str(x) for x in respuesta]

	print(" ".join(respuesta))


D()	