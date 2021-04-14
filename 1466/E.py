MOD = 1000000007
def solve():
	t = int(input())
	for _ in range(t):
		n = int(input())
		a = [int(x) for x in input().split()]
		s = sum(a)

		ans = 0

		for i in range(n):
			ans += (a[i] & s)*(a[i] | s)
			ans %= MOD

		print(ans)



solve()