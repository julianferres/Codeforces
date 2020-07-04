def fastio():
    import sys
    from io import StringIO
    from atexit import register
    global input
    sys.stdin = StringIO(sys.stdin.read())
    input = lambda : sys.stdin.readline().rstrip()
    sys.stdout = StringIO()
    register(lambda : sys.__stdout__.write(sys.stdout.getvalue()))
fastio()

def case():
    n,m = map(int, input().split())
    a = []
    for i in range(n):
        a.append([int(x) for x in input().split()])
    
    if n==1:
        if a[0][0]>1 or a[n-1][0]>1 or a[0][m-1]>1 or a[n-1][m-1]>1:
            print("NO")
            return
        for i in range(1,m-1):
            if a[0][i]>2: 
                print("NO")
                return
        print("YES")
        a = [[0 for i in range(m)] for i in range(n)]
        for i in range(n):
            for j in range(m):
                a[i][j] = 2
                if j == 0 or j ==  m-1:
                    a[i][j] = 1
        for i in a:
            print(*i)
        return

    if m == 1:
        if a[0][0]>1 or a[n-1][0]>1 or a[0][m-1]>1 or a[n-1][m-1]>1:
            print("NO")
            return
        for i in range(1,n-1):
            if a[i][0]>2:
                print("NO")
                return
        print("YES")
        a = [[0 for i in range(m)] for i in range(n)]
        for i in range(n):
            for j in range(m):
                a[i][j] = 2
                if i == 0 or i == n-1:
                    a[i][j] = 1

        for i in a:
            print(*i)
        return

    if a[0][0]>2 or a[n-1][0]>2 or a[0][m-1]>2 or a[n-1][m-1]>2:
        print("NO")
        return

    for i in range(1,n-1):
        if a[i][0]>3 or a[i][m-1]>3:
            print("NO")
            return
    for i in range(1,m-1):
        if a[0][i]>3 or a[n-1][i]>3:
            print("NO")
            return
    for i in range(n):
        for j in range(m):
            if a[i][j]>4:
                print("NO")
                return

    print("YES")
    a = [[0 for i in range(m)] for i in range(n)]
    for i in range(n):
        for j in range(m):
            a[i][j] = 4
            if i == 0 or j == 0 or i ==  n-1 or  j == m-1:
                a[i][j] = 3
    a[0][0]=2
    a[n-1][0]=2
    a[0][m-1]=2
    a[n-1][m-1]=2

    for i in a:
        print(*i)

t = int(input())
for _ in range(t):
    case()

        