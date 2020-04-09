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
 
t = int(input())
for _ in range(t):
    n,m = map(int, input().split())
    print("B" * (m - 1) + "W")
    for i in range(n - 1):
        print("B" * m)