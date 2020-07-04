from bisect import bisect_right
MAXA = 2005
n,p = map(int, input().split())
a = [int(x) for x in input().split()]
a.sort()
 
validos = []
 
for i in range(1,MAXA):
    se_hace_neg,mult = True, True
 
    for j in range(n):
        cant_menores = bisect_right(a,i+j)
        cant_menores-=j
        if(cant_menores%p == 0):
            mult = False
        if(cant_menores<=0):
            se_hace_neg = False
    
    if se_hace_neg and mult:
        validos.append(i)
 
 
print(len(validos))
print(*validos)
# print(" ".join([str(x) for x in validos]))