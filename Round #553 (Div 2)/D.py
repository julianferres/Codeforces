n = int(input())

suma = 0
dif = []
for i in range(n):
    a , b = map(int, input().split())
    suma += b*(n-1)
    dif.append(a-b)
dif = sorted(dif, reverse = True)
for j in range(n):
    suma+= j*dif[j]
print(suma)
