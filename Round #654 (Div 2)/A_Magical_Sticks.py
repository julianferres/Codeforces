t = int(input())
for _ in range(t):
    n = int(input())
    if n==1:
        print(1)
    elif(n&1):
        print(n//2 + 1)
    else:
        print(n//2)
