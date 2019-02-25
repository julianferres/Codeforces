import collections
def C():
	n = int(input())
	a = [int(x) for x in input().split()]
	col = dict(collections.Counter(a))
	ans = [[None]*n for x in range(n)]
	val = []
	for x in col:
		val+= [x]*(col[x]//4)

	if(not n%2):
		for x in col.values():
			if x%4:
				print("NO")
				return
		aux = 0
		for i in range(n//2):
			for j in range(n//2):
				if(aux<len(val)):
					ans[i][j]=val[aux]
					ans[n-1-i][j]=val[aux]
					ans[i][n-1-j] = val[aux]
					ans[n-1-i][n-1-j] = val[aux]
					aux+=1
		print("YES")
		for i in range(n):
			print(*ans[i])
				
	else:
		cnt_impar = 0
		cnt_2 = 0
		val2 = []
		valimp = 0
		val4 = []
		for x in col:
			if(col[x]%4==1 or col[x]%4==3):
				cnt_impar+=1
				valimp = x
			if(col[x]%4==2):
				cnt_2+=1
				val2+= [x]
				
			val4+= [x]*(col[x]//4)

		
		if(cnt_impar>1 or cnt_2>2*n//2):
			print("NO")
			return
						
		ans[n//2][n//2] = valimp
		
		aux = 0
		
		for i in range(n//2):
			for j in range(n//2):
				if(aux<len(val4)):
					ans[i][j]=val4[aux]
					ans[n-1-i][j]=val4[aux]
					ans[i][n-1-j] = val4[aux]
					ans[n-1-i][n-1-j] = val4[aux]
					aux+=1
		aux2 , i  = 0 , 0		
		while(aux2<len(val2) and i<n//2):
			ans[i][n//2]=val2[aux2]
			ans[n-1-i][n//2] = val2[aux2]
			aux2+=1
			i+=1
		if( aux2== len(val2) ):
			while(i<n//2 and aux<len(val4)):
				ans[i][n//2]=val4[int(aux)]
				ans[n-1-i][n//2]=val4[int(aux)]
				aux+=0.5
				i+=1
			
		i = 0
		while(aux2<len(val2) and i<n//2):
			ans[n//2][i]=val2[aux2]
			ans[n//2][n-1-i] = val2[aux2]
			aux2+=1
			i+=1
		if( aux2== len(val2) ):
			while(i<n//2 and aux<len(val4)):
				ans[n//2][i]=val4[int(aux)]
				ans[n//2][n-1-i]=val4[int(aux)]
				aux+=0.5
				i+=1


		print("YES")	
		for i in range(n):
			print(*ans[i])
			
C()
