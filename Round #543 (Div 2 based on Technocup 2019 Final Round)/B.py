def B():
    n = int(input())
    a = [int(x) for x in input().split()]
    sums = {}
    for i in range(n):
        for j in range(n):
            if(j>i):
                s = a[i]+a[j]
                if(s in sums):
                    sums[s]+=1
                else:
                    sums[s]=1
    print(max(sums.values()))
B()
