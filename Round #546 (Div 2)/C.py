n , m = map(int,input().split())
a , b = [] , []
for _ in range(n):
    aux = [int(x) for x in input().split()]
    a.append(aux)
for _ in range(n):
    aux = [int(x) for x in input().split()]
    b.append(aux)

def diagonalOrder(a,b):
    for line in range(1,n+m):
        start_col = max(0,line-n)
        count = min(line,(m-start_col),n)
        aux_a = []
        aux_b = []
        for j in range(count):
            aux_a.append(a[min(n,line)-j-1][start_col+j])
            aux_b.append(b[min(n,line)-j-1][start_col+j])
        if(sorted(aux_a)!=sorted(aux_b)): return("NO")
    return("YES")


print(diagonalOrder(a,b))
