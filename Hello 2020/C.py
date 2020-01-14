n, m = map(int, input().split())

factorials = [1]
for i in range(1,n+1):
    factorials.append(factorials[-1]*i%m)
ans = 0
for i in range(1,n+1):
    ans += (factorials[i]*((n+1-i)**2)*factorials[n-i])%m
    ans %= m
print(ans)