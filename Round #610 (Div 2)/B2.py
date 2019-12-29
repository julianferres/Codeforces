from collections import  defaultdict
import itertools
T = int(input())
for i in range(T):
    n,p,k = map(int, input().split())
    a = [int(x) for x in input().split()]
    a.sort()
    cum = [0]+list(itertools.accumulate(a[:k]))
    g = defaultdict(list)
    for i in range(n):
        if i+1>=k:
            g[(i+1)%k].append(a[i])
    ans = 0
    for i in range(k):
        if p>=cum[i]:
            p_aux = p-cum[i]
        cumgroup = list(itertools.accumulate(g[i]))
        n_groups = 0
        while n_groups<len(cumgroup) and p_aux>=cumgroup[n_groups]:
            n_groups+=1
        ans = max(ans,i*(p>=cum[i])+n_groups*k) 
    print(ans)
