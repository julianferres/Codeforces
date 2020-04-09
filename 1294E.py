n, m = map(int, input().split())


def solve(actual, target):
    #print(actual, target)
    rots = {i: 0 for i in range(n)}
    for i, x in enumerate(actual):
        if x in target:
            rots[(i-target[x]) % n] -= 1
    # print(rots)
    return min([n+i+rots[i] for i in range(n)])


a = []
for _ in range(n):
    b = [int(x) for x in input().split()]
    a.append(b)
for i in range(n):
    for j in range(m):
        a[i][j] -= 1

ans = 0
for j in range(m):
    target = {m*i+j: i for i in range(n)}
    actual = [a[i][j] for i in range(n)]
    ans += solve(actual, target)
print(ans)
