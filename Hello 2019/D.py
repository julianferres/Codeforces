import random
def D():

	inputs = input().split()

	n , k  = int(inputs[0]) , int(inputs[1])

	divisors = set()

	for i in range(1,n//2+2):

		if(not n%i):
			divisors.add(i)
			divisors.add(n//i)

	random.seed(58)

	divisors = sorted(list(divisors))

	for i in range(k):
		n = random.choice(divisors)

		print(n)
		aux = []

		for d in divisors:
			if(not n%d):
				aux.append(d)

		divisors = aux

		print(divisors)


D()