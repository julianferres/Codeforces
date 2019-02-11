def E():
	n = int(input())
	c = [int(x) for x in input().split()]
	t = [int(x) for x in input().split()]
	
	if(c[0]!=t[0] or c[-1]!=t[-1]): 
		print("No")
		return
	
	for i in range(n-2):
		if((c[i]%2,c[i+1]%2,c[i+2]%2)==(0,1,1) and (t[i]%2,t[i+1]%2,t[i+1]%2) not in [(0,1,1),(0,0,1)]):
			print("No")
			return
		elif((c[i]%2,c[i+1]%2,c[i+2]%2)==(0,0,1) and (t[i]%2,t[i+1]%2,t[i+1]%2) not in [(0,1,1),(0,0,1)]):
			print("No")
			return
		
		elif((c[i]%2,c[i+1]%2,c[i+2]%2)==(1,0,0) and (t[i]%2,t[i+1]%2,t[i+1]%2) not in [(1,1,0),(1,0,0)]):
			print("No")
			return
		
		elif((c[i]%2,c[i+1]%2,c[i+2]%2)==(1,0,0) and (t[i]%2,t[i+1]%2,t[i+1]%2) not in [(1,1,0),(1,0,0)]):
			print("No")
			return
		
		else:
			if(c[i]%2!=t[i]%2 or c[i+1]%2!=t[i+1]%2 or c[i+2]%2!=t[i+2]%2):
				print("No")
				return
	
	print("Yes")

E()

