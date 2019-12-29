T = int(input())
for i in range(T):
    n,p,k = map(int, input().split())
    a = [int(x) for x in input().split()]
    a.sort()
    even = []
    odd = []
    for i in range(n):
        if i&1: even.append(a[i])
        else: odd.append(a[i])
    
    max1, max2 = 0, 0

    p1, p2 = p,p
    i1,i2 = 0, 1
    while i1<len(even) and p1>=even[i1]:
        p1-=even[i1]
        i1+=1
        max1+=2
    max1 += (2*i1+1<n and a[2*i1+1]<=p1)
    
    while i2<len(odd) and p2>=odd[i2]:
        p2-=odd[i2]
        i2+=1
        max2+=2
    max2 += (a[0]<=p2)
    p2-=a[0]
    max2 += (2*i2+1<n and a[2*i2+1]<=p2)

    print(max(max1,max2))



    