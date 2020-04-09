from math import ceil
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    x = n-m
    if x < int(ceil(n/2)):
        print(n*(n+1)//2-x)
    else:
        cadagrupo = x//(m+1)
        sobran = x % (m+1)
        cum = 0
        cum += sobran*(cadagrupo+1)*(cadagrupo+2)//2
        cum += (m+1-sobran)*(cadagrupo)*(cadagrupo+1)//2
        print(n*(n+1)//2-cum)
