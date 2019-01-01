import math

def number_of_ones_bit_representation(n):

	count = 0
	while(n>0):
		count += (n%2)
		n = n//2

	return count

def max_pot_two_under(n):

		return 2**int(math.log(n,2))



def C():

	inp = input().split()
	n , k = int(inp[0]) , int(inp[1])

	if(k > n):
		print("NO")
		return

	if(number_of_ones_bit_representation(n) > k):
		print("NO")
		return

	print("YES")

	count = 0
	power = max_pot_two_under(n)

	answer = []

	while(n>0):

		if(n-power >= k-(count+1)):
			answer.append(power)
			count += 1
			n -= power

		else: power //= 2

	answer = [str(x) for x in answer]
	print(" ".join(answer))

C()