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

	brackets = {}
	for i in range(n):
		aux = []
		s = input()
		suma = 0
		for i in s:
			if(i=='('): suma+=1
			else: suma-=1

		if not suma in brackets:
			brackets[suma]=["".join(stacked(s))]
		else:
			brackets[suma].append("".join(stacked(s)))

	emptys = 0
	pairs = 0


	if(0 in brackets):
		aux = []	
		for i in brackets[0]:
			if not i:
				emptys+=1
				continue
			aux.append(i)
		brackets[0] = aux

	used = set()

	pairs += emptys//2

	used_dict = {}

	for i in brackets:
		used_dict[i] = [0]*len(brackets[i])

	for i in brackets:
		if(i==0):continue
		if i in used: continue
		if -i not in brackets: continue

		used.add(i)
		used.add(-i)

		for idx_x in range(len(brackets[i])):
			for idx_y in range(len(brackets[-i])):
				
				if(used_dict[i][idx_x] or used_dict[-i][idx_y]):
					continue

				x = brackets[i][idx_x]
				y = brackets[-i][idx_y]

				a , b = x+y , y+x
				if((not len(stacked(a))) or (not len(stacked(b)))):
					pairs+=1
					used_dict[i][idx_x]=1
					used_dict[-i][idx_y]=1	
					break

	print(pairs)

C()
