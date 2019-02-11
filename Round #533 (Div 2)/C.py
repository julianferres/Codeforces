MOD = 10**9+7
import math
def C():

	n , l , r = map( int , input().split() )

	c0 = math.floor(r/3) - math.ceil(l/3) + 1
	c1 = math.floor((r-1)/3) - math.ceil((l-1)/3) + 1
	c2 = math.floor((r-2)/3) - math.ceil((l-2)/3) + 1

	dp = [[0 for _ in range(3)] for __ in range(n+1)]
	dp[1] = [c0%MOD , c1%MOD , c2%MOD]

	for i in range(2,n+1):
		for j in range(3):

			if(j%3 == 0): dp[i][j] = (c0*dp[i-1][0] + c1*dp[i-1][2] + c2*dp[i-1][1])%MOD
			elif(j%3 == 1): dp[i][j] = (c0*dp[i-1][1] + c1*dp[i-1][0] + c2*dp[i-1][2])%MOD
			else: dp[i][j] = dp[i][j] = (c0*dp[i-1][2] + c1*dp[i-1][1] + c2*dp[i-1][0])%MOD

	print(dp[n][0])

C()