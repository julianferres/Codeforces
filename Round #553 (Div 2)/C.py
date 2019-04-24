import math
M = 10**9+7
l, r = map(int, input().split())

tri = lambda x : x*(x+1)

def solve(x):

    if(x<4): return [0,1,3,7][x]
    g = int(math.log(x,2))
    i = x - 2**g + 1
    suma = 0
    if(g%2 == 0):
        n = ((2**g)-1)//3
        suma = tri(2*n)%M
        suma += (n+i)**2%M
    else:
        n = ((2**(g+1))-1)//3 #Cantidad de impares
        n_p = 2*n-2**(g)
        suma = n**2%M
        suma += tri(n_p+i)%M
    return suma%M

print((solve(r)-solve(l-1))%M)
