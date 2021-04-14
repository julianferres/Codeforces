def solve():
    n = int(input())
    s = input()

    if(s == "1"*n):
        print(0)
        return
    if(s == "0"*n):
        print(bin(2**(n-1))[2:])
        return 0

    i = 0
    ans = 0
    while i < n:
        while i + 1 < n and s[i + 1] == s[i]:
            i+=1
        if(i + 1 != n and s[i] == "1"): ans += ((1<<(i+1))-1)
        if(i + 1 != n and s[i] == "0"): ans += (1<<i)
        i+=1

    print(bin(ans)[2:])
solve()
