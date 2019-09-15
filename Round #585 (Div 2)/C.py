SI = lambda : input()
from collections import Counter

n = int(input())
a = SI()
b = SI()

def solve(n,a,b):
	d = Counter(a)+Counter(b)
	for i in d:
		if(d[i]&1):
			print(-1)
			return
	xa = d[a]//2
	newa = []
	newb = []
	for i in range(n):
		if(a[i]!=b[i]):
			newa.append((a[i],i))
			newb.append((b[i],i))
	a,b = newa,newb
	aux = len(a)
	if(aux==0):
		print(0)
		return
	canta = 0
	for i in a:
		if(i[0]=='a'):
			canta+=1
	if(canta&1):
		print(len(a)//2+1)
		print(a[0][1]+1,a[0][1]+1)
		a[0],b[0] = b[0],a[0]
			
	else:
		print(len(a)//2)
	lastA,lastB = -1,-1
	for i in range(aux):
		if(a[i][0]=='a'):
			if(lastA==-1):
				lastA=a[i][1]
			else:
				print(lastA+1,a[i][1]+1)
				lastA=-1
		else:
			if(lastB==-1):
				lastB=a[i][1]
			else:
				print(lastB+1,a[i][1]+1)
				lastB=-1
solve(n,a,b)




