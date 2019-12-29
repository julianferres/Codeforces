T = int(input())
for _ in range(T):
    a,b,c,r = map(int, input().split())
    a,b = min(a,b), max(a,b)
    l = max(a,c-r)
    r = min(b,c+r)
    print(b-a) if r<=l else print(b-a-(r-l))



    