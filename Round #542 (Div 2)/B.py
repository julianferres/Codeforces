def B():
    n = int(input())
    a = [int(x) for x in input().split()]
    d = {i:[] for i in range(1,n+1)}
    d[0]= [0,0]
    for i in range(2*n):
        d[a[i]].append(i)
    ans = 0
    for i in range(n):
        a , b = d[i] , d[i+1]
        ans+= min(abs(b[0]-a[0])+abs(b[1]-a[1]) , abs(b[0]-a[1])+abs(b[1]-a[0]))
    print(ans)

B()
