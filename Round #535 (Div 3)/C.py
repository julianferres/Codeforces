def C():
	n = int(input())
	s = input()
	cases = ["BGR","BRG","GBR","GRB","RBG","RGB"]
	dist = [0]*6

	for i in range(n):
		for j in dist: j+=1
		if(s[i]=='B'):
			if(i%3==0):
				dist[0]-=1
				dist[1]-=1
			elif(i%3==1):
				dist[2]-=1
				dist[4]-=1
			else:
				dist[3]-=1
				dist[5]-=1
				
		elif(s[i]=='G'):
			if(i%3==0):
				dist[2]-=1
				dist[3]-=1
			elif(i%3==1):
				dist[0]-=1
				dist[5]-=1
			else:
				dist[1]-=1
				dist[4]-=1

		else:
			if(i%3==0):
				dist[4]-=1
				dist[5]-=1
			elif(i%3==1):
				dist[1]-=1
				dist[3]-=1
			else:
				dist[0]-=1
				dist[2]-=1

	a = 0
	for i in range(6):
		if(dist[i]<dist[a]): a = i

	ans = cases[a]*(n//3)
	ans+= cases[a][:n%3]
	cost = 0

	for i in range(n):
		if(ans[i]!=s[i]):
			cost+=1

	print(cost)
	print(ans)
C()