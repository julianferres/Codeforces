def cleaning(string):
	aux = []
	for i in string:
			if(not len(aux)):
				aux.append(i)
				continue
			if(aux[-1]=='(' and i==')'):
				aux.pop()
				continue
			aux.append(i)

	return "".join(aux)

def C():

	n = int(input())
	pairs = 0

	counterLeft = {}
	counterRight = {}
	emptys = 0

	for i in range(n):
		s = cleaning(input())
	
		if not s:
			emptys+=1
			continue
		if('(' in s and ')' in s):
			continue
		if('(' in s):
			if(len(s) in counterLeft): counterLeft[len(s)]+=1
			else: counterLeft[len(s)] = 1
		if(')' in s):
			if(len(s) in counterRight): counterRight[len(s)]+=1
			else: counterRight[len(s)] = 1

	pairs += emptys//2

	for i in counterLeft:
		if i not in counterRight: continue
		pairs += min(counterLeft[i] , counterRight[i])

	print(pairs)


C()
