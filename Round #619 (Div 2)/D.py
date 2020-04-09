import sys
n, m, k = map(int, input().split())
if(k > 4*n*m-2*n-2*m):
    print("NO")
    sys.exit()

# Siempre yes
print("YES")
comp = [(m-1, 'R'), (m-1, 'L')]
comp += (n-1)*[(1, 'D'), (m-1, 'R'), (m-1, 'UDL')] + [(n-1, 'U')]
ans = []
for x in comp:
    if x[0] == 0:
        continue
    if k <= 0:
        break
    if x[0]*len(x[1]) <= k:
        ans.append(x)
        k -= x[0]*len(x[1])
    else:
        cycles = k//len(x[1])
        if cycles:
            ans.append((cycles, x[1]))
        if k % len(x[1]):
            ans.append((1, x[1][:k % len(x[1])]))
        k = 0
print(len(ans))
for i in ans:
    print(i[0], i[1])
