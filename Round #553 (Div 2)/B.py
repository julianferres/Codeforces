def B():
    n , m = map(int, input().split())
    a = []
    for i in range(n): a.append(sorted(list(set([int(x) for x in input().split()]))))
    print(a)

B()
