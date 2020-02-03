from math import log10
t = int(input())
for _ in range(t):
    A, B = map(int, input().split())
    cnt = 0
    while(9*int((cnt+1)*'1') <= B):
        cnt += 1
    print(A*cnt)
