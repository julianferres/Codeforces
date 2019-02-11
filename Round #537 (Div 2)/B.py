n , k , m = map(int , input().split())
a = sorted([int(x) for x in input().split()])

prefix_sum = [sum(a)]
for i in range(n):
	prefix_sum.append(prefix_sum[-1]-a[i])

ans = (sum(a)+min(m,n*k))/n
for i in range(1,min(m,n-1)+1):
	a = (prefix_sum[i] + min(m-i,k*(n-i)))/(n-i)
	ans = max(ans,a)

print(ans)