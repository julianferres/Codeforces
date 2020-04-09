from math import ceil, inf
t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    prom, cnt = 0, 0
    s = set()
    glob = 0
    for i in range(n-1):
        if a[i] == -1 and a[i+1] != -1:
            s.add(a[i+1])
        if a[i] != -1 and a[i+1] == -1:
            s.add(a[i])
        if a[i] != -1 and a[i+1] != -1:
            glob = max(glob, abs(a[i+1]-a[i]))
    if not s:
        print(0, 0)
    else:

        M, m = max(s), min(s)
        #print("M", M, "m", m)
        k = int((M+m)/2)
        print(max([glob, M-k, m-k]), k)
