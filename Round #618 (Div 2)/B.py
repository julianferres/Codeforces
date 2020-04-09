t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    n *= 2
    if n == 2:
        print(abs(a[-1]-a[0]))
    else:
        print(a[n//2]-a[n//2-1])
