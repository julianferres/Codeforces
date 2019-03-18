n = int(input())
a = [int(x) for x in input().split()]

d = {}
for i in a:
    if(i in d): d[i]+=1
    else: d[i]=1
ans = -float('inf')
for i in d:
    aux = 0
    for j in range(6):
        if(i+j in d): aux+=d[i+j]
    ans = max(ans, aux)

print(ans)
