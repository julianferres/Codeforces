def D():

	n = int(input())
	s = input()

	colours = ["B", "G" , "R"]
	ans = ""

	i = 0
	c = []
	cnt = 1
	while(i<n-1):
		if(s[i+1]==s[i]):
			cnt+=1
		else:
			c.append(cnt)
			cnt = 1

		i+=1
	c.append(cnt)

	i = 0
	counter = 0
	for e in c:
		if(e==1):
			ans+=s[i]
			i+=1
		else:
			counter+= e//2
			for j in range(e):
				if(j%2):
					if(i==n-1):
						ans+=colours[(colours.index(s[i-1])+1)%3]
					else:
						if(s[i+1]==s[i]):
							ans+=colours[(colours.index(s[i+1])+1)%3]
						else:
							ans+=colours[3-colours.index(s[i-1])-colours.index(s[i+1])]
				else:
					ans+=s[i]
				i+=1
	
	print(counter)
	print(ans)


D()
