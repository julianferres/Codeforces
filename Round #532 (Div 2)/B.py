def B():
    
   n , m = map(int, input().split())

   counter = {i:0 for i in range(1,n+1)}

   inp = [int(x) for x in input().split()]
   ans = ""
   colours = n


   for i in inp:
   		if(counter[i]==0):
   			colours-=1

   		counter[i]+=1	
   		if not colours:
   			ans+='1'
   			for i in range(1,n+1):
	   			counter[i]-=1
	   			if(not counter[i]):
	   				colours+=1
	   	else:
	   		ans+='0'

   print(ans)







    
    
    
    

B()