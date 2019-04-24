def B():
    n , m = map(int, input().split())
    a = []
    for i in range(n): a.append([int(x) for x in input().split()])

    aux = a[0]
    if(n==1 and aux==[0]*m):
        print("NIE")
        return

    cnt = {}
    for i in range(n-1):
        if([a[i][0]]*m==a[i]):
            if(a[i][0] in cnt):
                cnt[a[i][0]]+=1
            else: cnt[a[i][0]]=1

    for i in range(n):
        x = a[i][0]
        if(a[i]!= [x]*m):
            print("TAK")
            l = ['1']
            acum = a[0][0]
            for i in range(1,n):
                for j in range(m):
                    if(a[i][j]!=acum):
                        acum ^= a[i][j]
                        l.append('{}'.format(j+1))
                        break
            print(" ".join(l))
            return
    for i in cnt:
        if(cnt[i]%2):
            if(i!=0):
                print("TAK")
                print(" ".join(['1']*n))
                return
        print("NIE")

B()
