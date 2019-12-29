t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    
    actXor = 0
    for i in a: actXor^=i
    suma = sum(a)
    if suma==2*actXor:
        print(0)
        print("")
    else:
        print(2)
        print(actXor, suma+actXor)