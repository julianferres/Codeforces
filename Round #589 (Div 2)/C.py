M = 10**9+7
x, n = map(int,input().split())
import math
def primeFactors(n):
	primes = set()
	while n%2 == 0:
		primes.add(2)
		n//=2
	for i in range(3,int(math.sqrt(n))+1,2):
		while(n%i==0):
			primes.add(i)
			n//=i
	if(n>2):
		primes.add(n)
	return primes
def modexp( x, y, p ):
	res = 1
	while(y>0):
		if(y & 1):
			res*= x
			res%=p
		y >>= 1
		x%=p
		x*= x


	return res%p

primes = primeFactors(x)
ans = 1
for p in primes:
	cnt = 0;
	alphap = 1
	aux = n
	while(n/(p**alphap)>0):
		cnt += n//(p**alphap)
		alphap+=1
	
	cnt = cnt%(M-1)
	ans*= modexp(p,cnt,M)
	ans%=M
	

print(ans%M)
