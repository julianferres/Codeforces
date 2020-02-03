from math import ceil,inf
T = int(input())
for _ in range(T):
    n,d = map(int,input().split())
    m = inf
    for i in range(int(d**0.5)+1):
        m = min(m, i+ceil(d/(i+1)))
    print("YES") if min(d,m)<=n else print("NO")

