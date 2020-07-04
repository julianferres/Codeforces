def _mex(a):
    s = set(a)
    i = 0
    while i in s:
        i+=1
    return i

def is_sorted(a):
    for i in range(len(a)-1):
        if a[i]>a[i+1]:
            return False
    return True


def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    
    ans = []

    for i in range(2*n):
        if is_sorted(a):
            break
        
        mex = _mex(a)

        if mex < n:
            a[mex] = mex
            ans.append(mex+1)
        
        else:
            for i in range(n):
                if a[i] != i:
                    ans.append(i+1)
                    a[i] = mex
                    break
    
    print(len(ans))
    print(*ans)
    

t = int(input())
for _ in range(t):
    solve()