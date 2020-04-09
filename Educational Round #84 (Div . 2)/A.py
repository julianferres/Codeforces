t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    if n>=k**2 and n&1==k&1:
        print("YES")
    else:
        print("NO")