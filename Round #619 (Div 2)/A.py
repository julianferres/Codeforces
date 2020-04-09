t = int(input())
for _ in range(t):
    a = input()
    b = input()
    c = input()
    n = len(a)
    possible = True
    for i in range(n):
        if a[i] != c[i] and b[i] != c[i]:
            print("NO")
            possible = False
            break
    if possible:
        print("YES")
