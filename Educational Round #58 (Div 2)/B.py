def B():

	s = input()

	o_bracket = set()
	c_bracket = set()
	colon = set()
	
	for i in range(len(s)):
		if(s[i]=='['): o_bracket.add(i)
		if(s[i]==']'): c_bracket.add(i)

	if(len(o_bracket)*len(c_bracket)==0):
		print(-1)
		return
	l , r = min(o_bracket) , max(c_bracket)

	for i in range(l,r+1):
		if(s[i]==':'): colon.add(i)

	if(len(colon)<2):
		print(-1)
		return

	ll , rr  = min(colon) , max(colon)

	count_vl = 0
	for i in range(ll,rr+1):
		if(s[i]=='|'): count_vl+=1

	print(count_vl+4)


B()