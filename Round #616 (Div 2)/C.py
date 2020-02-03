from math import inf
t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())
    a = [int(x) for x in input().split()]
    ans = 0
    if k >= m-1:
        for i in range(m):
            x = i
            y = n-1-(m-1)+i
            act = max(a[x], a[y])
            ans = max(ans, act)
        print(ans)
        continue

    for i in range(k+1):
        x = i
        y = n-1-k+i
        v = []
        for j in range(m-k):
            w = x+j
            z = y-(m-1-k)+j
            v.append(max(a[w], a[z]))
        aux = inf
        for j in range(len(v)):
            aux = min(aux, v[j])
        ans = max(ans, aux)
    print(ans)
