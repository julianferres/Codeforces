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

test = int(input())
def divisors(n):
    ans = []
    d = 1
    while d*d<=n:
        if d*d == n:
            ans.append(d)
        elif  n%d == 0:
            ans.append(d)
            ans.append(n//d)
        d+=1
    return ans

#print(divisors(5))
#print(divisors(12))
        
        

for _ in range(test):
    n = int(input())
    a = [int(x) for x in input().split()]
    dp = [1 for i in range(n)] 
    for i in range(n):
        act_idx = i+1
        for d in divisors(act_idx):
            prev_idx = d-1
            if a[prev_idx]<a[i]:
                dp[i] = max(dp[i], dp[prev_idx]+1)
    print(max(dp))
