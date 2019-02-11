def C():

	message = input()
	k = int(input())

	candy_count = 0
	snowflake_count = 0

	for char in message:

		if(char == '?'): candy_count+=1
		if(char == '*'): snowflake_count+=1

	if(k < len(message)-2*(candy_count+snowflake_count)):
		print("Impossible")
		return

	if(snowflake_count == 0 and k>len(message)-candy_count):
		print("Impossible")
		return

	if(k>len(message)-candy_count-snowflake_count):
		ans_start = ""
		ans_end = ""
		idx_snowflake = message.index('*')
		for char in message[:idx_snowflake]:
			if(char != '?'): ans_start+= char

		for char in message[idx_snowflake:]:
			if(char not in ['*', '?']): ans_end+=char

		while( k>len(message)-candy_count-snowflake_count):
			ans_start+=ans_start[-1]
			k-=1
		print(ans_start+ans_end)
		return

	if(k == len(message)-candy_count-snowflake_count):

		ans = ""
		for char in message:
			if(char not in ['*','?']): ans += char

		print(ans)
		return	

	if(k < len(message)-candy_count-snowflake_count):
		ans = ""
		aux = set()
		caracteres_a_remover = len(message)-candy_count-snowflake_count-k
		idx = 0
		while(caracteres_a_remover>0 and idx<len(message)):
			if(message[idx] in ['*','?']):
				aux.add(idx-1)
				caracteres_a_remover-=1

			idx+=1


		for i in range(len(message)):
			if(message[i] not in ['*','?'] and i not in aux):
				ans+=message[i]

		print(ans)








C()