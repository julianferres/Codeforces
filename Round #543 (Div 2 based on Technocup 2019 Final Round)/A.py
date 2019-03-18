def A():
    n , m , k = map(int , input().split())
    p = [int(x) for x in input().split()]
    s = [int(x) for x in input().split()]
    c = [int(x) for x in input().split()]

    dic = {i:[] for i in range(1,m+1)}
    for i in range(n):
        dic[s[i]].append((p[i],i+1))

    ans = k
    for i in dic:
        if(max(dic[i])[1] in c):
            ans-=1
    print(ans)



A()
