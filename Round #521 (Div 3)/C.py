def C():

	n = int(input())
	array = [int(x) for x in input().split()]
	total_sum = sum(array)

	count = [0]*1000002
	for element in array: count[element]+=1

	ans = []

	for i in range(n):

		count[array[i]]-=1
		partial_sum = total_sum - array[i]
		
		if(partial_sum%2==0 and int(partial_sum/2)<1000007 and count[partial_sum//2]>0):
			ans.append(str(i+1))

		count[array[i]]+=1


	print(len(ans))
	print(" ".join(ans))

C()
