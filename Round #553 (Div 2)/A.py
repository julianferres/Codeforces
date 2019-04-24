n = int(input())
s = input()
ans = float('inf')
for i in range(n-3):
    aux = 0
    aux += min(abs(ord(s[i])-ord('A')), 26-abs(ord(s[i])-ord('A')))
    aux += min(abs(ord(s[i+1])-ord('C')), 26-abs(ord(s[i+1])-ord('C')))
    aux += min(abs(ord(s[i+2])-ord('T')), 26-abs(ord(s[i+2])-ord('T')))
    aux += min(abs(ord(s[i+3])-ord('G')), 26-abs(ord(s[i+3])-ord('G')))
    ans = min(ans,aux)

print(ans)
