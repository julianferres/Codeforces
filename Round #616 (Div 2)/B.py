t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    flag = False
    for i in range((n+1)//2):
        if a[i] < i or a[n-1-i] < i:
            print("No")
            flag = True
            break
    if not flag:
        if n & 1:
            print("Yes")
        else:
            if a[n//2-1] <= n//2-1 and a[n//2] <= n//2-1:
                print("No")
            else:
                print("Yes")
