I = lambda : int(input())
SI = lambda : input()
M = "Monocarp"; B = "Bicarp"
def solve(n,s):
	lsum = 0
	cl = 0
	rsum = 0
	cr = 0

	for i in range(n//2):
		if(s[i]=='?'):
			cl+=1
		else:
			lsum+=int(s[i])

	for i in range(n//2,n):
		if(s[i]=='?'):
			cr+=1
		else:
			rsum+=int(s[i])

	dif = lsum-rsum
	if(dif==0):
		if(cl==cr):print(B)
		else: print(M)
		return
	if(cl==cr):
		print(M)
		return
	if((dif>0 and cl>cr) or (dif<0 and cl<cr)):
		print(M)
		return

	#Casos dif<0 y cl>cr
	if(dif>0):
		dif= -dif
		cl,cr = cr,cl
	difc = cl-cr 
	if(dif+difc//2*9==0):
		print(B)
	else:
		print(M)








	










n = I()
s = SI()
solve(n,s)