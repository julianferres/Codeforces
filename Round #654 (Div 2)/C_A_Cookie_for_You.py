Y = "Yes"
N = "No"
t = int(input())
for _ in range(t):
    v,c,n,m = map(int, input().split())
    if n+m > v+c:
        print(N)
    else:
        rest = min(max(v,c)-min(v,c), n)
        mm,MM = min(v,c), max(v,c)
        MM -= rest
        n-= rest
        pos = (mm>=m or m == 0) and (MM+mm-m>=n)
        print(Y) if pos else print(N)
