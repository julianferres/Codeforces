n, x, y = map(int,input().split())
a = [int(x) for x in input().split()]

for i in range(n):
	flag = True
	j = max(0,i-x)
	while(j<= min(n-1,i+y)):
		if(j==i):
			j+=1
			continue
		if(a[j]<=a[i]):
			flag = False
			break
		j+=1
	if(flag):
		print(i+1)
		break

	
