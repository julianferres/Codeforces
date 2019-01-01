def B():

	mod = 998244353
	n = int(input())

	word = input()

	countFirst = 0
	countLast = 0

	while(word[0] == word[countFirst]):
		countFirst += 1

	while(word[-1] == word[n-countLast-1]):	
		countLast +=1

	if(word[0]==word[-1]):
		print((countLast+1)*(countFirst+1)%mod)
		return

	print((countFirst+countLast+1)%mod)

B()