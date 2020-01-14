from bisect import bisect_left


def gcd(a, b):
    while(b):
        a %= b
        a, b = b, a  # Swap para tener el mas chico en b
    return a


def divisors(n):
    d = []
    for i in range(1, int(n**0.5)+1):
        if (n % i == 0):
            d.append(i) if(i*i == n) else d.extend([i, n//i])
    return list(sorted(d))


def solve():
    n = int(input())
    if n == 1:
        print(1, 1)
        return
    for i in divisors(n):
        if i*i <= n or gcd(i, n//i) > 1:
            continue
        else:
            print(n//i, i)
            return


solve()
