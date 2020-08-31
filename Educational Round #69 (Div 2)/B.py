n = int(input())
a = [int(x) for x in input().split()]

m = max(a)
m_idx = a.index(m)

possible = True
for i in range(1,m_idx):
	if(a[i]<a[i-1]):
		possible = False
for i in range(m_idx+2,n):
	if(a[i]>a[i-1]):
		possible = False

print("YES") if possible else print("NO")	
