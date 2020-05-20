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

def test():
	n, k = map(int,input().split())
	a = [int(x) for x in input().split()]
	
	if k not in a:
		print("no")
		return 
		
	if n==1 and a[0]==k:
		print("yes")
		return
	
	a = [a[i]>=k for i in range(n)]
	
	for i in range(n):
		if sum(a[i:i+3])>=2:
			print("yes")
			return
	print("no")
	

t = int(input())
for _ in range(t):
	test()
