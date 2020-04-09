from collections import defaultdict
int(input())
b = [int(x) for x in input().split()]
c = [b[i]-i for i in range(len(b))]
d = defaultdict(list)
for i, x in enumerate(c):
    d[x].append(i)

ans = b[0]
for value in d:
    act = 0
    for i in d[value]:
        act += b[i]
    ans = max(ans, act)

print(ans)
