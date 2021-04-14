def solve_case():
	n = int(input())
	a = [int(x) for x in input().split()]
	ans = 0
	for i in range(1, n):
		if(a[i] > a[i-1]):
			continue

		ceros_atras = len(str(a[i-1])) - len(str(a[i]))
		x = 10 **ceros_atras
		# print("Ceros_atras", ceros_atras)
		if(a[i] * x > a[i-1]):
			ans += ceros_atras
			a[i] *= x
		elif (a[i] * x + (x - 1) <= a[i-1]):
			ans += ceros_atras + 1
			a[i] *= x * 10
		else:
			ans += ceros_atras
			a[i] = a[i-1] + 1

	return ans

t = int(input())

for i in range(t):
	print("Case #{}: {}".format(i+1, solve_case()))