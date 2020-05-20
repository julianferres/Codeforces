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
def smallest(n):
    for d in range(2,n+1):
        if n%d == 0:
            return d

for _ in range(test):
    n, k = map(int, input().split())
    if not n&1:
        print(n+2*k)
    else:
        print(n+smallest(n)+2*(k-1))
