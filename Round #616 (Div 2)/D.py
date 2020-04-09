s = input()
n = len(s)
cnt = [[0]*26 for i in range(n+1)]
for i in range(1, n+1):
    for c in range(26):
        cnt[i][c] = cnt[i-1][c] + (ord(s[i-1])-ord('a') == c)

q = int(input())
for i in range(q):
    l, r = map(int, input().split())
    l -= 1
    r -= 1
    flag = 0
    for c in range(26):
        flag += (cnt[r+1][c]-cnt[l][c] > 0)
    if l == r or s[l] != s[r] or flag >= 3:
        print("Yes")
    else:
        print("No")
