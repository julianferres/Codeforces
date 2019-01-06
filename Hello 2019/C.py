def stacked(string):
	aux = []
	for i in string:
			if(not len(aux)):
				aux.append(i)
				continue
			if(aux[-1]=='(' and i==')'):
				aux.pop()
				continue

			aux.append(i)

	return aux


def C():

	n = int(input())

	brackets = []

	for i in range(n):
		aux = []
		s = input()
		brackets.append("".join(stacked(s)))

	emptys = 0
	pairs = 0

	aux = []

	for i in brackets:
		if not i:
			emptys+=1
			continue
		aux.append(i)

	brackets = aux
	used = [0]*len(brackets)

	pairs += emptys//2
	for i in range(len(brackets)):
		for j in range(len(brackets)):
			if(not(used[i] or used[j])):
				if(not len(stacked(brackets[i]+brackets[j]))):
					pairs+=1
					used[i]=1
					used[j]=1


	print(pairs)




C()