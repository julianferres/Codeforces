def A():
    n = int(input())
    c = []
    for _ in range(n):
        l,r = map(int,input().split())
        c.append((l,r))
    k = int(input())
    for i in range(n):
        l,r = c[i]
        if(l<=k<=r):
            print(n-i)
            break


A()
