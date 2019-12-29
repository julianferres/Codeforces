t = int(input())

for _ in range(t):
    n, k1, k2 = map(int, input().split())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    
    print("YES") if max(a)>max(b) else print("NO")

    