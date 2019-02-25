def D():
    n , m = map(int,input().split())
    c = {i:[] for i in range(1,n+1)}
    ans = [0]*(n)
    for _ in range(m):
        a , b = map(int , input().split())
        c[a].append(b)


    m = -float('inf')
    maximos = []
    for j in c:
        m = max(len(c[j]), m)
    for i in range(1,n+1):
        if(len(c[i])==m): maximos.append(i)
    for i in range(1,n+1):
        ans[i-1]+= (m-1)*n
        aux = -float('inf')
        for x in maximos:
            aux2 = float('inf')
            for j in c[x]:
                aux2 = min(aux2,(j-x)%n)

            aux = max(aux, (x-i)%n+aux2 )
        ans[i-1]+=aux




    print(*ans)

D()
