# from itertools import reduce
n = int(input())
a = [int(x) for x in input().split()]

b = [[int(j == i) for j in range(n)] for i in range(n)]
def xor(a, b):
	return [a[i] ^ b[i] for i in range(n)]

# for x in b:
# 	print(*x)
# print()

for i in range(n-1):
	aux = [xor(b[j], b[j+1]) for j in range(len(b)-1)]
	b = aux[:]
for x in b:
	print(*x)
print()
