def is_prime(n):

	for i in range(2,int(n**0.5)+1):
		if(n%i==0):
			return False
	return True


n = int(input())

edges = [(i,i%n+1) for i in range(1,n+1)]
n_edg = n
i = 1
while(not is_prime(n_edg)):
	edges.append((i,n//2+i))
	n_edg+=1
	i+=1	



print(n_edg)
for e in edges:
	print(*e)

