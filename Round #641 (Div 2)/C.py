from collections import defaultdict, Counter
n = int(input())
a = [int(x) for x in input().split()]

def fact(n):
    gaps = [1,2,2,4,2,4,2,4,6,2,6]
    length, cycle = 11, 3
    f, fs, nxt = 2, [], 0
    while f * f <= n:
        while n % f == 0:
            fs.append(f)
            n //= f
        f += gaps[nxt]
        nxt += 1
        if nxt == length:
            nxt = cycle
    if n > 1: fs.append(n)
    
    return dict(Counter(fs))
	
# ~ print(fact(24))

min_p = defaultdict(list)
cnt = defaultdict(int)
for i in range(n):
	fa = fact(a[i])
	for p in fa:
		cnt[p]+=1
		act = fa[p]
		l = min_p[p]
		l.append(act)
		l.sort()
		min_p[p] = l[:2]

ans = 1
# ~ print(min_p)
# ~ print(cnt)
for p in min_p:
	l = min_p[p]
	l.sort()
	if cnt[p] <= n-2:
		exp = 0
	elif cnt[p] == n-1:
		exp = l[0]
	else:
		exp = l[-1]
	# ~ print(p,exp)
	ans *= p**exp
print(ans)
