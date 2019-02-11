def A():
	n = int(input())
	m = [input() for _ in range(n)]

	cnt = 0

	for i in range(1,n-1):
		for j in range(1,n-1):
			if(m[i][j]==m[i-1][j-1]==m[i+1][j+1]==m[i-1][j+1]==m[i+1][j-1]=='X'):
				cnt+=1
	print(cnt)

A()