t = int(input())

for case in range(t):
	n = int(input())
	a = [int(x) for x in input().split()]

	ans = 0

	for i in range(n-1):
		mindex = i
		for j in range(i, n):
	   		if(a[j] < a[mindex]):
	   			mindex = j;
		ans += mindex - i + 1
		a[i: mindex+1] = a[i: mindex+1][::-1]
		# print(i, mindex, a)

	print("Case #{}: {}".format(case+1, ans))