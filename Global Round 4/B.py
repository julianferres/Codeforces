s = input()
cum = [0]*len(s)

for i in range(len(s)-2,-1,-1):
	cum[i] = cum[i+1]+ int((s[i]=='v' and s[i+1]=='v'))


ans = 0
for i in range(len(s)):
	if(s[i]=='o'):
		ans += (cum[0]-cum[i])*cum[i]

print(ans)

