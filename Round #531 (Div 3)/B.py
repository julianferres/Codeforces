def B():

	n , k = map(int,input().split())
	s = [int(x) for x in input().split()]

	ans = [-1]*n
	color = dict()

	for i in range(k):
		ans[i]=i+1
		color[i+1] = [s[i]]

	for i in range(n):
		if(ans[i]==-1):
			for c in color:
				if(s[i] not in color[c]): 
					ans[i] = c
					color[c].append(s[i])
					break

	if(-1 in ans):
		print("NO")
		return


	print("YES")
	ans = [str(x) for x in ans]
	print(" ".join(ans))

B()