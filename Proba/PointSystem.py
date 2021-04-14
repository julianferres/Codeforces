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


class PointSystem:
	def oddsOfWinning(self, pointsToWin, pointsToWinBy, skill):
		n = 1000
		p = [[0 for i in range(n)] for j in range(n)]
		p[0][0] = 1

		for i in range(n-1):
			for j in range(n-1):
				if(max(i, j) >= pointsToWin and max(i, j) - min(i, j) >= pointsToWinBy):
					continue

				p[i+1][j] += p[i][j] * skill/100.0
				p[i][j+1] += p[i][j] * (100-skill)/100.0

		ans = 0.0
		for i in range(n):
			for j in range(n):
				if(i > j and i >= pointsToWin and i - j >= pointsToWinBy):
					ans += p[i][j]

		return ans

# x = PointSystem()
# print(x.oddsOfWinning(2, 1, 40))
# print(x.oddsOfWinning(4, 5, 50))
# print(x.oddsOfWinning(3, 3, 25))