from math import log
M = 998244353

def op(n):
	out = 0
	if(n==0):
		return 0
	d = int(log(n,10))+1
	for i in range(d):
		out+= 11*(10**(2*i))*(n%10)%M
		n//=10
	return out


n = int(input())
a = [int(x) for x in input().split()]

dig = [int(log(x,10))+1 for x in a]

cntdig = [0]*11

for l in dig:
	cntdig[l]+=1

ans = 0
for ai in a:
	d = int(log(ai,10))+1
	for d_o in range(1,11):
		if(d_o>d):
			ans+=cntdig[d_o]*op(ai)
			ans%=M
		elif(d_o==d):
			ans+=cntdig[d_o]*op(ai)
		else:
			ans+=cntdig[d_o]*op(ai%(10**d_o))
			ans+=2*cntdig[d_o]*(ai//(10**d_o))*(10**(2*d_o))
			ans%=M

print(ans%M)
