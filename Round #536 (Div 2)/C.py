n = int(input())
a = [int(x) for x in input().split()]
a = sorted(a)
ans = 0
for i in range(n//2):
	ans+= (a[i]+a[n-1-i])**2

print(ans)