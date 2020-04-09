n = int(input())
P = []
for i in range(n):
    x, y = map(int, input().split())
    P.append((x, y))
barx, bary = 0, 0
for i in range(n):
    barx += P[i][0]
    bary += P[i][1]
barx, bary = barx/n, bary/n
for i in range(n):
    P[i] = (P[i][0]-barx, P[i][1]-bary)

s = set(P)
possible = True
for x in s:
    if (-x[0], -x[1]) not in s:
        print("NO")
        possible = False
        break
if possible:
    print("YES")
