import math

def divisors(n):
	divs = set() 

	for i in range(1,math.ceil(n**0.5)+1):

		if(not n%i): 
			divs.add(i)
			divs.add(n//i)
	
	return list(sorted(divs))

def C():

	n = int(input())

	fun_values = []

	for d in divisors(n):

		fun_values.append( d + n*(d-1)//2)

	fun_values = [str(x) for x in fun_values]
	print(" ".join(fun_values))



C()