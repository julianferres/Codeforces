def power(x):
    ans = 0
    while(x != 1):
        ans += 1
        x >>= 1
    return ans


t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = [int(x) for x in input().split()]
    cnt = [0]*80
    for i in range(m):
        cnt[power(a[i])] += 1
    if sum(a) < n:
        print(-1)
    else:
        ans, idx = 0, 0
        while(idx < 60):
            if((1 << idx) & n):
                for i in range(idx):
                    cnt[i+1] += cnt[i]//2
                    cnt[i] = cnt[i] & 1
                if cnt[idx]:
                    n -= (1 << idx)
                    cnt[idx] -= 1
                else:
                    j = idx+1
                    while(not cnt[j] and j < 60):
                        j += 1
                    cnt[j] -= 1
                    for ii in range(idx, j):
                        ans += 1
                        cnt[ii] += 1
                    n -= (1 << idx)
                    cnt[idx] -= 1
            idx += 1
        print(ans)
