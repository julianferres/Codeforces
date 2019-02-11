from math import gcd
def D():

	n = int(input())
	matrix = [0 for _ in range(n)]
	for i in range(n):
		a = bin(int(input(), 16))[2:]
		matrix[i] = '0'*(n-len(a))+ a

	ans = 0
	i = 0

	while(i<n):
		j = i+1
		while(j<n and matrix[i]==matrix[j]): #Recorro por filas
			j+=1
		ans = gcd(ans,j-i)

		col = 0
		while(col<n):
			l = col + 1
			while(l<n and matrix[i][col]==matrix[i][l]): #Recorro por columnas
				l+=1
			ans = gcd(ans, col-l)
			col = l
		i = j

	print(ans)

D()