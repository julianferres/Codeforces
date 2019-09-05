n = int(input())
d = int(input())
e = int(input())
ans = float('inf')
n_d = 0
while(n_d*d<=n):
	ans = min(ans,(n-n_d*d)%(5*e))
	n_d+=1

print(ans)
