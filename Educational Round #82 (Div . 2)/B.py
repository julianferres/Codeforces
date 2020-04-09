def ceil(x, y=1): return int(-(-x // y))


t = int(input())
for _ in range(t):
    n, g, b = map(int, input().split())
    necesariosg = ceil(n, 2)
    gc = necesariosg//g
    if necesariosg-gc*g:
        ultimoG = gc*(g+b)+(necesariosg-gc*g)
    else:
        ultimoG = gc*(g+b)-b

    print(ultimoG) if ultimoG >= n else print(n)
