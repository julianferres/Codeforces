n = int(input())
a = []
for i in range(n):
    a.append([int(x) for x in input().split()[1:]])

def has_ascent(a):
    for i in range(len(a)-1):
        if a[i]<a[i+1]:
            return True
    return False
ans = 0
ascent = 0
info = []
for i in a:
    if has_ascent(i):
        ascent+=1
    else:
        info.append((min(i),max(i)))
ans+= 2*ascent*(n-ascent)
ans+= ascent*(ascent)
men = sorted([i[0] for i in info])
may = sorted([i[1] for i in info])
from bisect import bisect_left
for i in range(len(may)):
    ans+= bisect_left(men,may[i])
print(ans)
