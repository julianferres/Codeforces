def intesect(a,b):
    l = max(a[0],b[0]); r = min(a[1],b[1])
    return l<r

a = []
b = []
n = int(input())
for i in range(n):
    sa,ea,sb,eb = map(int, input().split())
    a.append((sa,ea,i))
    b.append((sb,eb,i))

a.sort()
b.sort()

def solve(a,b):
    for i in range(n-1):
        if intesect((a[i][0],a[i][1]),(a[i+1][0],a[i+1][1])) and not intesect((b[a[i][2]][0],b[a[i][2]][1]),(b[a[i+1][2]][0],b[a[i+1][2]][1])):
            print("NO")
            return
    b,a = a,b
    for i in range(n-1):
        if intesect((a[i][0],a[i][1]),(a[i+1][0],a[i+1][1])) and not intesect((b[a[i][2]][0],b[a[i][2]][1]),(b[a[i+1][2]][0],b[a[i+1][2]][1])):
            print("NO")
            return
    print("YES")
    
solve(a,b)
    