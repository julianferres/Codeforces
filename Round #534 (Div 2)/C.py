def C():
	s = input()
	a , b =  0 , 0

	for x in s:
		if(x=='1'):
			if(b%2==0):
				print(4,3)
			else:
				print(4,1)
			b+=1

		else:
			if(a%2==0):
				print(1,1)
			else:
				print(3,1)
			a+=1

C()


