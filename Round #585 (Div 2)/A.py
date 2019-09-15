II = lambda : int(input())

a1 = II()
a2 = II()
k1 = II()
k2 = II()
n = II()

if(k1>k2):
    k1,k2 = k2,k1
    a1,a2 = a2,a1
auxM = min(a1,n//k1)
restM = n-auxM*k1
M = auxM+min(a2,restM//k2)
if((k1-1)*a1+(k2-1)*a2>=n):
    m = 0
else:
    m = n-((k1-1)*a1+(k2-1)*a2)
   
print(m,M)
