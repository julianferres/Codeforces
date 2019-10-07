n, m = map(int,input().split())
from collections import Counter

ady = set()
col = [-1 for i in range(n)]

for _ in range(m):
	a,b = map(int,input().split())
	ady.add((a-1,b-1))
	ady.add((b-1,a-1))


col[0]=1

def solve(n,ady,col):
	lastUsed = 1
	possible = True
	for i in range(n):
		actCol = -1
		for j in range(n):
			if((i,j) not in ady and col[j]!=-1):
				if(actCol!=-1 and col[j]!=actCol):
					print(-1)
					return
				actCol = col[j]
		if actCol==-1:
			if(lastUsed==3):
				print(-1)
				return
			else:
				lastUsed+=1
				actCol = lastUsed

		col[i] = actCol

	cntr = Counter(col)
	if(cntr[1]*cntr[2]+cntr[2]*cntr[3]+cntr[3]*cntr[1]!=m):
		print(-1)
		return
	if(len(cntr)<3):
		print(-1)
		return
	for i in range(n):
		for j in range(i+1,n):
			if(col[i]!=col[j] and (i,j) not in ady):
				print(-1)
				return
	print(*col)





solve(n,ady,col)

