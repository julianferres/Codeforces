t = int(input())
for _ in range(t):
    k = int(input())
    a = [int(x) for x in input().split()]
    finded = False
    for i in range(len(a)-1):
        if abs(a[i]-a[i+1])>=2:
            print("YES")
            print(i+1,i+2)
            finded = True
            break
    if not finded: print("NO")

    