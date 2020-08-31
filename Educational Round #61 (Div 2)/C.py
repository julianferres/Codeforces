import collections

n , q  = map(int , input().split())
sections = [0]*n
p = []
for _ in range(q):
    l , r = map(int , input().split())
    p.append((l,r))
    for j in range(l,r+1):
        sections[j-1]+=1

aux = n-collections.Counter(sections)[0]
number1 = [0]*n
number2 = [0]*n

for i in range(n):
    if(sections[i]==1):
        for j in range(i,n):
            number1[j]+=1
    elif(sections[i]==2):
        for j in range(i,n):
            number2[j]+=1

ans = -float('inf')
for i in range(len(p)):
    for j in range(len(p)):
        if(j>i):
            a, b = p[i]
            c, d = p[j]
            if(a>c):
                a , c = c , a
                b , d = d , b
            aux1 = number1[b-1]-number1[a-1]+1*(sections[a-1]==1)
            aux2 = number1[d-1]-number1[c-1]+1*(sections[c-1]==1)
            aux3 = abs(number2[c-1]-number2[min(b,d)-1])+1*(sections[c-1]==2)
            if(b<c): aux3 = 0
            ans = max(ans , aux-(aux1+aux2+aux3))
print(ans)
