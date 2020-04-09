n = int(input())
a = [int(x) for x in input().split()]
bits = {i: [] for i in range(33)}
for i in range(n):
    cnt = 0
    x = a[i]
    while(x):
        if(x & 1):
            bits[cnt].append(i)
        x >>= 1
        cnt += 1


find = False
for i in range(32, -1, -1):
    if(len(bits[i]) == 1):
        k = bits[i][0]
        ans = [a[k]] + a[:k]+a[k+1:]
        print(*ans)
        find = True
        break
if not find:
    print(*a)
