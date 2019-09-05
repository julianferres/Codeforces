n, m = map(int,input().split())
a = []
ans = 2
for i in range(n):
	a.append(list(input()))

dp = [[0 for i in range(m)] for j in range(n)]
dp[0][0]=1
for i in range(1,n):
	if(a[i][0]=='#'): dp[i][0]=0
	else: dp[i][0]=dp[i-1][0]
for i in range(1,m):
	if(a[0][i]=='#'): dp[0][i]=0
	else: dp[0][i]=dp[0][i-1]
for i in range(1,n):
	for j in range(1,m):
		dp[i][j] = 0 if a[i][j]=='#' else dp[i-1][j]+dp[i][j-1]

if(dp[-1][-1]==0):
	print(0)
else:
	pi,pj = n-1,m-1
	while(pi and pj):
		if(pi!=n-1 or pj!=m-1):
			a[pi][pj]='#'
		if(dp[pi-1][pj]>0):
			pi-=1
		else:
			pj-=1
	if(pi):
		while(pi):
			a[pi][pj]='#'
			pi-=1
	if(pj):
		while(pj):
			a[pi][pj]='#'
			pj-=1

	dp[0][0]=1
	for i in range(1,n):
		if(a[i][0]=='#'): dp[i][0]=0
		else: dp[i][0]=dp[i-1][0]
	for i in range(1,m):
		if(a[0][i]=='#'): dp[0][i]=0
		else: dp[0][i]=dp[0][i-1]
	for i in range(1,n):
		for j in range(1,m):
			dp[i][j] = 0 if a[i][j]=='#' else dp[i-1][j]+dp[i][j-1]
	if(dp[-1][-1]==0):
		print(1)
	else:
		print(2)


