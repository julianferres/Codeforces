def solve(c, bit):
    if not len(a) or bit < 0:
        return 0
    l, r = [], []
    for i in c:
        if(((i >> bit) & 1) == 0):
            l.append(i)
        else:
            r.append(i)

    if not len(l):
        return solve(r, bit-1)
    if not len(r):
        return solve(l, bit - 1)

    return min(solve(l, bit-1), solve(r, bit-1)) + (1 << bit)


n = int(input())
a = [int(x) for x in input().split()]
print(solve(a, 30))
