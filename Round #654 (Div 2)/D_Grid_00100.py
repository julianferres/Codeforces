from math import *
from heapq import heappush, heappop
from collections import *

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
    n,k = map(int, input().split())
    a = [["0"]*n for i in range(n)]

    r,c = 0,0
    for i in range(k):
        a[r][c] = "1"
        r,c = r+1,c+1
        if(r==n):
            c +=1
            r = 0
        c%=n

    maxR,maxC,minR,minC = 0,0,inf,inf

    for i in range(n):
        row = [a[i][j]=="1" for j in range(n)]
        col = [a[j][i]=="1" for j in range(n)]
        maxR = max(maxR, sum(row))
        minR = min(minR, sum(row))
        maxC = max(maxC, sum(col))
        minC = min(minC, sum(col))

    print((maxR - minR)**2 + (maxC - minC)**2)
    for i in a:
        print("".join(i))
    