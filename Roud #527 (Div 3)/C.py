def xfixes_validos(n, word, fixes):


	countPS = 0
	salida = [i for i in fixes]
	for i in range(1,n):

		prefix = word[0:i]
		for i in range(2*n-2):
			if(prefix == salida[i]):
				salida[i] = 'P'
				countPS -=1
				break

	if(countPS != -(n-1)): return 0

	for i in range(1,n):

		sufix = word[i:n]
		for i in range(2*n-2):
			if(sufix == salida[i]):
				salida[i] = 'S'
				countPS +=1
				break

	return 0 if(countPS != 0) else salida
	
def C():

	n = int(input())
	inputs = [input() for i in range(2*n-2)]
	longfixes = []

	for x in inputs:
		if (len(x)==n-1): longfixes.append(x)

	if (longfixes[0][1:] == longfixes[1][:-1]):
		word1 = longfixes[0][0]+longfixes[1]
		fixes1 = xfixes_validos(n , word1 , inputs)
		if(fixes1):
			s = ""
			for i in range(2*n-2): s+= fixes1[i]
			print(s)
			return

	if (longfixes[1][1:] == longfixes[0][:-1]): 
		word2 = longfixes[1][0]+longfixes[0]
		fixes2 = xfixes_validos(n , word2 , inputs)
		if(fixes2):
			s = ""
			for i in range(2*n-2): s+= fixes2[i]
			print(s)


C()