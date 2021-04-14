n = int(input())
ans = 0
for i in range(1, 10**6+1):
    ans += (int(str(i) + str(i)) <= n)

print(ans)
