M = 998244353
n = int(input())
a = [int(x) for x in input().split()]

from math import log
"""l = len(str(a[0]))"""

ans = 0

"""for i in range(l+1):
	for j in range(len(a)):
		ans+= (10**(2*i))*(a[j]%10)%M
		a[j]//=10


print((n*11*ans)%M)"""

def op(n):
	out = 0
	if(n==0):
		return 0
	d = int(log(n,10))+1
	for i in range(d+1):
		out+= 11*(10**(2*i))*(n%10)%M
		n//=10
	return out

for ai in a:
	ans+= (n*op(ai))%M
	ans%=M

print(ans)
