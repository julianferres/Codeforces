def B():

	n , k = map( int , input().split() )
	s = input()

	counter = {}

	l = 1
	for i in range(n-1):

		if(s[i]!=s[i+1]):
			if(s[i] not in counter):
				counter[s[i]]=int(l/k)
			else:
				counter[s[i]]+=int(l/k)
			l = 1

		else:
			l+=1
			continue

	if(s[-1] not in counter):
		counter[s[-1]] = int(l/k)
	else:
		counter[s[i]]+= int(l/k)

	if(len(counter)):
		print(max(counter.values()))
		return

	print(0)

B()