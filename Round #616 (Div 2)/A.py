t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    cnt = 0
    for i in range(len(s)):
        if int(s[i]) & 1:
            if cnt == 1:
                ansj = i
                cnt += 1
                break
            else:
                ansi = i
            cnt += 1

    if cnt < 2:
        print(-1)
    else:
        print(s[ansi]+s[ansj])
