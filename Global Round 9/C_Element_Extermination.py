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

def case():
    n = int(input())
    a = [int(x) for x in input().split()]
    print("YES") if a[0] < a[-1] else print("NO")


t = int(input())
for _ in range(t):
    case()
