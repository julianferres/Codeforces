h,w = map(int, input().split())
r = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]

def modexp( x, y, p ):
	res = 1
	while(y>0):
		if(y & 1):
			res*= x
			res%=p
		y >>= 1
		x*= x

	return res%p

M = 10**9+7
canuse = [[True]*w for i in range(h)]
flag = 1
for i in range(h):
	for j in range(r[i]):
		canuse[i][j] = False
	if(r[i]<w):
		canuse[i][r[i]]= False
for j in range(w):
	for i in range(c[j]):
		canuse[i][j] = False
	if(c[j]<h):
		canuse[c[j]][j]= False
exp = 0
for i in range(h):
	for j in range(w):
		exp+= int(canuse[i][j])

for i in range(h):
	for j in range(w):
		if(r[i]>=j+1 and c[j]==i):
			flag=0
for i in range(h):
	for j in range(w):
		if(c[j]>=i+1 and r[i]==j):
			flag = 0

if(flag == 0):
	print(0)
else:
	print(modexp(2,exp,M))