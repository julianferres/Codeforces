import heapq

def D():

	n , k = map(int , input().split())
	array = [int(x) for x in input().split()]

	counter = {}

	for element in array:
		if element in counter: counter[element]+=1
		else: counter[element] = 1

	s = [(count , key) for key, count in counter.items()]
	s.sort(reverse = True)

	ans = []

	for i in range(len(s)):
		divisor = 1

		while(s[i][0]//divisor > 0):
			ans.append([[s[i][0]//divisor], s[i][1]])
			divisor+=1

	ans.sort(reverse = True)

	output = []

	for i in range(k):
		output.append(str(ans[i][1]))

	print(" ".join(output))

D()