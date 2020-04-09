from math import ceil
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    if(m == 0):
        print(0)
        continue
    if(m == 1):
        prim0 = (n-1)//2
        rest = n-1-prim0
        #print(prim0, rest)
        print(n*(n+1)//2-(prim0+1)*prim0//2-rest*(rest+1)//2)
        continue
    q = n//m
    r = n % m
    print(n*(n+1)//2-m*(q-1)*q//2 - r*(r+1)//2)
