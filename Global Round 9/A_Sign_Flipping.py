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
    n = int(input())
    a = [int(x) for x in input().split()]
    for i in range(n):
        if i&1:
            a[i] = -abs(a[i])
        else:
            a[i] = abs(a[i])
    
    print(*a)

