import math
l = [1, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401]
q = int(input())
for _ in range(q):
	b = int(input())
	if(int(math.log2(b))< int(math.log2(b+1))):
		print(l[int(math.log2(b))])	
	else:
		dig = int(math.log2(b))+1
		print(2**(dig)-1)
