def C():
	n , k = map( int , input().split() )
	a = [int(x) for x in input().split()]
	s = input()

	dmg = 0
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

	i=0
	seq = 0
	while(i<n):
		ordered = sorted(a[i:i+c[seq]], reverse = True)
		dmg+= sum(ordered[:k])
		i+=c[seq]
		seq+=1


	print(dmg)




C()