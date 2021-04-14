from collections import defaultdict
def solve():
	n = int(input())
	a = []
	m = defaultdict(int)
	for i in range(n):
		a.append(input())
		m[a[i]] += 1
	# print(m)
	for x in m:
		# print(x)
		cnt1 = m[x]
		aux = "!" + x
		cnt2 = m[aux] if aux in m else 0
		if(cnt1 == 1 and cnt2 <= 1):
			print(x)
			return 0

	print("satisfiable")

solve()

