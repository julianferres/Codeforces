def D():

	n = int(input())
	s=input()
	
	c = [0,0,0]

	for d in s:
		if(d=='0'): c[0]+=1
		elif(d=='1'): c[1]+=1
		else: c[2]+=1

	a = [x for x in s]

	for i in range(n):
	    act = s[i]
	    if c[int(act)] > n//3:
	        for j in range(int(act)):
	            if c[j] < n//3:
	                c[j]+=1
	                c[int(a[i])]-=1
	                a[i]=str(j)
	                break


	for i in range(n-1, -1, -1):
	    act = s[i]
	    if c[int(act)] > n//3:
	        for j in range(2,-1,-1):
	            if c[j] < n//3:
	                c[j]+=1
	                c[int(s[i])]-=1
	                a[i]=str(j)
	                break

	print(''.join(a))


D()