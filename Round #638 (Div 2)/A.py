test = int(input())
for _ in range(test):
	n = int(input())
	a = 2**n
	for i in range(1,n//2):
		a+=2**i
	b= 0 
	for i in range(n//2,n):
		b+=2**i
	print(abs(b-a))

	