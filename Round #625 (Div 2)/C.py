n = int(input())
s = input()


def remove(s):
    actC = 'a'
    actI = -1
    for i in range(len(s)):
        if i > 0:
            if ord(s[i])-ord(s[i-1]) == 1 and s[i] > actC:
                actC = s[i]
                actI = i
        if i < len(s)-1:
            if ord(s[i])-ord(s[i+1]) == 1 and s[i] > actC:
                actC = s[i]
                actI = i

    return actC, actI


ans = 0
actIdxToRem = remove(s)[1]
while actIdxToRem != -1:
    s = s[:actIdxToRem]+s[actIdxToRem+1:]
    ans += 1
    actIdxToRem = remove(s)[1]
print(ans)
