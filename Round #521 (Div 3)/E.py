def E():

	n = int(input())
	topics = [int(x) for x in input().split()]

	counter = {}
	for e in topics:
		if(e in counter): counter[e]+=1
		else: counter[e] = 1

	s = list(counter.values())
	s.sort(reverse = True)

	choose = [s[0]]
	act = s[0]

	for i in range(1,len(s)):
		aux = min(act//2,s[i])

		if(aux == 0): break #Terminamos
		choose.append( aux*(2**(i+1)-1) )
		#Agrego como si hubiese terminado aca, y sigo
		act = aux


	print(max(choose))






E()