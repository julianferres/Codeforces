def calcular(x):
	ans = 0
	act = 0

	for i in range(32):
		if((1<<i)&x):
			act += 1
		else:
			ans += act // 2
			act = 0
	ans += act // 2

	return ans

todos = []
N = int(input())

for n in range(1, N+1):
	suma = 0
	for i in range(1<<n):
		suma += calcular(i)

	todos.append(suma)

print(todos)



