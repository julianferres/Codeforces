from collections import Counter
q = int(input())
for _ in range(q):
    n, m = map(int,input().split())
    a = []
    max_row = 0
    max_col = 0
    cols = [0]*m
    rows = [0]*n
    for i in range(n):
        s = input()
        a.append(s)
        rows[i] = Counter(s)['*']


    for i in range(n):
        for j in range(m):
            if(a[i][j]=='*'):
                cols[j]+=1
    result = n*m
    for i in range(n):
        for j in range(m):
            x = max(0,m-rows[i])
            y = max(0,n-cols[j])

            flag = a[i][j]=='.'
            result = min(result, max(0,x+y-flag))

    print(result)
