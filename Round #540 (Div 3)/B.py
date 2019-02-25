n = int(input())
a = [int(x) for x in input().split()]
a = [(-1)**i*a[i] for i in range(n)]

left_sum = [0]
right_sum = [0]

for i in range(n-1):
	left_sum.append(left_sum[-1]+a[i])
for i in range(n-1):
	right_sum = [right_sum[0]+a[n-1-i]]+ right_sum
cnt = 0

for i in range(n):
	if(left_sum[i]-right_sum[i]==0):
		cnt+=1				
print(cnt)
