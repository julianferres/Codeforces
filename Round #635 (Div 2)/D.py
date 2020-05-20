def fastio():
    import sys
    from io import StringIO
    from atexit import register
    global input
    sys.stdin = StringIO(sys.stdin.read())
    input = lambda : sys.stdin.readline().rstrip()
    sys.stdout = StringIO()
    register(lambda : sys.__stdout__.write(sys.stdout.getvalue()))
fastio()

from math import inf
f = lambda a,b,c: (a-b)**2+(b-c)**2+(a-c)**2

test = int(input())
for _ in range(test):
	nr,ng,nb = map(int,input().split())
	r = [int(x) for x in input().split()]
	g = [int(x) for x in input().split()]
	b = [int(x) for x in input().split()]
	n = nr+nb+ng
	a = []
	for i in r:
		a.append((i,0))
	for i in g:
		a.append((i,1))
	for i in b:
		a.append((i,2))
	a.sort()

	lr,rr,lg,rg,lb,rb = [-inf]*n,[inf]*n,[-inf]*n,[inf]*n,[-inf]*n,[inf]*n
	if a[0][1]==0:
		lr[0] = a[0][0]
	if a[0][1]==1:
		lg[0] = a[0][0]
	if a[0][1]==2:
		lb[0] = a[0][0]
	if a[n-1][1]==0:
		rr[n-1] = a[n-1][0]
	if a[n-1][1]==1:
		rg[n-1] = a[n-1][0]
	if a[n-1][1]==2:
		rb[n-1] = a[n-1][0]
	# print(lr,rr,lg,rg,lb,rb)
	for i in range(1,n):
		lr[i] = lr[i-1]
		lg[i] = lg[i-1]
		lb[i] = lb[i-1]
		if a[i][1]==0:
			lr[i] = max(a[i][0],lr[i])
		if a[i][1]==1:
			lg[i] = max(a[i][0],lg[i])
		if a[i][1]==2:
			lb[i] = max(a[i][0],lb[i])

	for i in range(n-2,-1,-1):
		rr[i] = rr[i+1]
		rg[i] = rg[i+1]
		rb[i] = rb[i+1]
		if a[i][1]==0:
			rr[i] = min(a[i][0],rr[i])
		if a[i][1]==1:
			rg[i] = min(a[i][0],rg[i])
		if a[i][1]==2:
			rb[i] = min(a[i][0],rb[i])
	best = inf
	for i in range(n):
		if(a[i][1] == 0):
			best = min(best,f(a[i][0],lg[i],rb[i]))
			best = min(best,f(a[i][0],lb[i],rg[i]))
		if(a[i][1] == 1):
			best = min(best,f(a[i][0],lr[i],rb[i]))
			best = min(best,f(a[i][0],lb[i],rr[i]))
		if(a[i][1] == 2):
			best = min(best,f(a[i][0],lr[i],rg[i]))
			best = min(best,f(a[i][0],lg[i],rr[i]))

	print(best)