n = int(input())
r = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
solor = 0
for i in range(n):
    if r[i] and not b[i]:
        solor += 1
if sum(r) > sum(b):
    print(1)
elif solor == 0 and sum(b) >= sum(r):
    print(-1)
else:
    dif = sum(b)-sum(r)
    print(1+(dif+1+solor-1)//solor)
