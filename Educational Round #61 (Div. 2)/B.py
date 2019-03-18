def B():
    n = int(input())
    a = [int(x) for x in input().split()]
    suma = sum(a)
    m = int(input())
    q = [int(x) for x in input().split()]
    a = sorted(a ,reverse =True)

    for i in q:
        print(suma-a[i-1])  

B()
