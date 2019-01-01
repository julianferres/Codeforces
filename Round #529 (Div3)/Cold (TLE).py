def two_powers_generator(n):

	powers = []
	i = 0
	while(2**i<=n):
		powers.append(2**i)
		i+=1
	return powers


def add_representation(n , k , dic):


	if(k == 1 and (n,k) not in dic): return False

	if((n,k) in dic) : return True

	for i in two_powers_generator(n)[:-1]:
		
		if((n-i,k-1) in dic):
			
			a = dic.get((n-i , k-1))
			c = a + [i]
			dic[(n,k)]= c
			return True
	
		add_representation(n-i,k-1,dic)

		if((n-i,k-1) in dic):
			
			a = dic.get((n-i , k-1))
			c = a + [i]
			dic[(n,k)]= c
			return True


	return False


def is_representable(n , k , dic):

	if((n,k) in dic): return True

	for i in two_powers_generator(n):
	
		add_representation(n-i , k-1 , dic)

		if((n-i,k-1) not in dic) : continue

		a = dic.get((n-i , k-1))

		c = a+[i]
		dic[(n,k)] = c
		return True

	return False

def C():

	inp = input().split()
	n , k = int(inp[0]) , int(inp[1]) 

	dic = {}

	powers = two_powers_generator(n)
	for i in powers:

		dic[(i,1)] = [i]

	if not is_representable(n,k,dic):
		print("NO")
		return

	print("YES")
	a = dic.get((n,k))
	a = [str(x) for x in a]
	print(" ".join(a))


C()