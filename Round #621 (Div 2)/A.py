t = int(input())
for _ in range(t):
    n, d = map(int, input().split())
    v = [int(x) for x in input().split()]
    pos = 1
    while d > 0 and pos < n:
        if d >= pos*v[pos]:
            v[0] += v[pos]
            d -= pos*v[pos]
        else:
            aux = d//pos
            v[0] += aux
            d -= (aux+1)*pos
        pos += 1
    print(v[0])
