from decimal import *
getcontext().prec = 28
n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

d = []
ans = 0
for i in range(n):
    if(a[i]==0):
        if(b[i]==0):
            ans+=1
        continue
    d.append(-Decimal(b[i])/Decimal(a[i]))

from collections import Counter
c = Counter(d)
aux = 0
for i in c:
    aux=max(aux,c[i])
print(aux+ans)
