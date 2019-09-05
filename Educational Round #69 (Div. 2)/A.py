T = int(input())

for _ in range(T):
	n = int(input())
	a = [int(x) for x in input().split()]
	if(n<=2):
		print(0)
		continue
	a = sorted(a,reverse = True)
	l = a[1]
	k = min(l-1,len(a)-2)
	print(k)
