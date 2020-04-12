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
from collections import deque
t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    d = deque(a)
    ans = []
    turn = 0
    while (len(d)):
        if not turn:
            ans.append(d.pop())
        else:
            ans.append(d.popleft())
        turn ^= 1
        

    ans.reverse()
    print(*ans)