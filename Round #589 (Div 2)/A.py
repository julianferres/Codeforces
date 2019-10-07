from collections import Counter

ans = -1

l,r  = map(int, input().split())

for i in range(l,r+1):
	c = Counter(str(i))
	flag = True
	for j in c:
		if c[j]>1:
			flag = False
		
	if flag: ans= i
print(ans)
