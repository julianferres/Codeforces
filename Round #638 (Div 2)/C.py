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

test = int(input())
for _ in range(test):
	n,k = map(int, input().split())
	s = list(input())
	s.sort()
	i = 0
	if s[0] == s[k-1]:
		if k<n and s[-1]==s[k]:
			c = s[k]
			cnt = (n+k-1)//k - 1
			print("".join([s[k-1]]+[c]*cnt))
		else:
			print("".join(s[k-1:]))
	else:
		print(s[k-1])
	
	
