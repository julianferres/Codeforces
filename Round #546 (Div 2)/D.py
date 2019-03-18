n , m = map(int,input().split())
p = [int(x) for x in input().split()]
a = []
for _ in range(m):
    l,r = map(int,input().split())
    a.append((l,r))
goods = set()
for i in a:
    l,r =i
    if(r==p[-1]):goods.add(l)

father = {i:set() for i in range(1,n+1)}
for i in a:
    l,r = i
    father[l].add(r)
for i in p:
