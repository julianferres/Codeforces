n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

d = {}
ans = 0
for i in range(n):
    if(a[i]==0):
        if(b[i]==0):
            ans+=1
        continue
    if(-b[i]/a[i] in d):
        d[-b[i]/a[i]]+=1
    else:
        d[-b[i]/a[i]]=1
        
if(len(d)!=0): ans += max(d.values())
print(ans)
