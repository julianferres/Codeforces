def E():

	n = int(input())

	brackets = input()

	if(n%2):
		print(0)
		return

	cumm_brackets = []
	

	for b in brackets:
		if(not len(cumm_brackets)): cumm_brackets.append(1 if b=='(' else -1)
	
		else:
			cumm_brackets.append(cumm_brackets[-1]+1 if b=='(' else cumm_brackets[-1]-1)

	if(abs(cumm_brackets[-1])!= 2):
		print(0)
		return

	if(cumm_brackets[-1]==2):

		if(-1 in cumm_brackets):
			print(0)
			return

		last_under_2_index = 0
		for i in range(n-1):
			if cumm_brackets[i]<2:
				last_under_2_index = i

		answer = 0
		for i in range(last_under_2_index+1,n):
			if(brackets[i]=='('): answer+=1


	if(cumm_brackets[-1]== -2):

		if(min(cumm_brackets)<=-3):
			print(0)
			return

		for first_under_minus_2_index in range(n):
			if cumm_brackets[first_under_minus_2_index]==-1:
				break

		answer = 0
		for i in range(first_under_minus_2_index+1):
			if(brackets[i]==')'): answer+=1


	print(answer)

E()