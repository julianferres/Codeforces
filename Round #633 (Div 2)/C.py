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

def op(x, target):
    ans = 0
    while (x+(2**ans-1) < target):
        ans += 1
    # print(x,ans)
    return ans


for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    ans = 0
    for i in range(1, n):
        if(a[i-1]<=a[i]):
            continue
        ops = op(a[i], a[i - 1])
        # print("ops",ops)
        a[i] = a[i-1]
        ans = max(ans, ops)

    # print(a)
    print(ans)