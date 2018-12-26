def A():

	a = input()

	b = ""

	if(not (len(a)%2)):
		index = -1
		for i in range(len(a)):

			index += (-1)**(i+1)*i
			b += a[index]



	if( len(a)%2):
		index = 0
		for i in range(len(a)):

			index += (-1)**(i)*i
			b += a[index]

	print(b[::-1])

A()