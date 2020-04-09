from collections import Counter
t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    suma = sum(a)
    ans = 0
    for i in range(n):
        if a[i] == 0:
            a[i] += 1
            ans += 1
    if sum(a) == 0:
        ans += 1
    print(ans)
