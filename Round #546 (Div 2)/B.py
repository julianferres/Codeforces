n,k = map(int,input().split())
counts = 3+(n-1)*2
aux = min(k-1,n-k)
counts+= (n-1+aux)
print(counts)
