from collections import Counter

n, I = map(int,input().split())
a = [int(x) for x in input().split()]

count = Counter(a)
aux = sorted([(el,count[el]) for el in count])

left = [aux[0]]

for i in range(1,len(aux)):
	left.append((aux[i][0],left[-1][1]+aux[i][1]))

l, r = 0, len(aux)-1
dif = len(aux)

T = max(len(aux)-(dif-2**(int((I*8)/n))),0)
s = sum([aux[i][1] for i in range(T)])
ans = s
i = 0

while(i+T<len(aux)):
	s += (aux[i+T][1]-aux[i][1])
	ans = max(ans,s)
	i+=1		

print(n-ans) if (T!=0) else print(0)


	
