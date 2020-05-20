def fastio():
    import sys
    from io import StringIO
    from atexit import register
    global input
    sys.stdin = StringIO(sys.stdin.read())
    input = lambda : sys.stdin.readline().rstrip()
    sys.stdout = StringIO()
    register(lambda : sys.__stdout__.write(sys.stdout.getvalue()))
fastio()

def t():

	n,k = map(int, input().split())
	a = [int(x) for x in input().split()]
	sa = set(a)
	if len(sa)>k:
		print(-1)
		return
	for i in range(1,n+1):
		if i not in sa and len(sa)<k:
			sa.add(i)
	sa = list(sa)
	print(n*k)
	ans = n*sa
	print(*ans)




test = int(input())
for _ in range(test):
	t()