def B():

	n = int(input())

	array = input().split()
	array1 = [int(x) for x in array]
	array2 = [int(x) for x in array]

	stability = lambda x : max(x)-min(x)

	max1 = max(array1)
	min2 = min(array2)

	array1.remove(max1)
	array2.remove(min2)

	output = min(stability(array1),stability(array2))

	print(output)

B()