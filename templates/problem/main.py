I = lambda : int(input())
LI = lambda : [int(x) for x in input().split()]
MI = lambda : map(int, input().split())
SI = lambda : input()

"""
#Leer de archivo
for line in sys.stdin:
    ...
"""

"""
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
"""


