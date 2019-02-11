def D():

	n = int(input())
	s = input()

	c0 = 0
	c1 = 0
	c2 = 0

	for c in s:
		if(c=='0'): c0+=1
		elif(c=='1'): c1+=1
		else: c2+=1

	if(c0==c1==c2):
		print(s)
		return

	ans = ""

	if(c0< n//3):
		if(c1 == n//3):
			for e in s:
				if(c0<n//3):
					if(e=='2'):
						ans+='0'
						c0+=1
				else: ans+=e
				i+=1

		print(ans)
		return

		if(c1 < n//3):
			for e in s:
				if(c0<n//3):
					if(e=='2'):
						ans+='0'	
						c0+=1
				else: ans+=e
			
			for e in s:
				if(c1 < n//3):
					if(e=='2'):
						ans+='1'
						c1+=1
				else: ans+=e

		print(ans)
		return

			
		if(c1 > n//3 and c2> n//3):
			for e in s:
				if(c0<n//3):
					if(e in ['2','1']):
						ans+='0'
						c0+=1
				else: ans+=e
	
	
		if(c1 > n//3 and c2<= n//3):
			
			for e in s:
				if(c0<n//3):
					if(e in ['1']):
						ans+='0'
						c0+=1
				else: ans+=e

			j = c1 - (n//3-c2)

			for e in s:
				if(c2 < n//3):
					if(e == '1'):
						if(j>0):
							j-=1
							ans+='1'
							continue
						ans+='2'
						c2+=1
				else: ans+=e

	print(ans)
	return

	if(c0 == n//3):

		if(c1< n//3):
			i=0
			while(c1<n//3):
				if(s[i] == '2'):
					ans+='1'
					c1+=1
				else: ans+=s[i]
				i+=1

		if(c1> n//3):
			j = c1 - (n//3-c2)
			i=0
			while(c1 > n//3 and j>0 and i<n):

				if(s[j] == '1'):
					if(j>0):
						j-=1
						continue
					ans+='2'
					c1-=1

				else: ans+=s[i]
				j-=1


	if(c0 > n//3):

		if(c1> n//3):
			j = c1+c0 - (n//3-c2)
			while(c2 < n//3):

				if(s[j] in ['0','1']):
					if(j>0):
						j-=1
						continue
					ans+='2'
					c2+=1

				else: ans+=s[i]

		if(c1 == n//3):

			j = c0 - (n//3-c2)
			while(c2 < n//3):

				if(s[j] in ['0']):
					if(j>0):
						j-=1
						continue
					ans+='2'
					c2+=1

				else: ans+=s[i]

		if(c1 < n//3):
			j = n-1
			while(c2 < n//3):
				if(s[j] == '0'):
					ans+='2'
					c2+=1
				else: ans+=s[j]
				j-=1
			while(c1 < n//3):
				if(s[j] == '0'):
					ans+='1'
					c1+=1
				else: ans+=s[j]
				j-=1

			
			ans = s[: n -len(ans)] + ans[::-1]

	print(ans)

D()