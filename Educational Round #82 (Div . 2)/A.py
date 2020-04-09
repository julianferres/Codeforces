from collections import Counter
t = int(input())
for _ in range(t):
    s = input()
    firstOne = -1
    lastOne = -1
    for i in range(len(s)):
        if s[i] == '1':
            if firstOne == -1:
                firstOne = i
            else:
                lastOne = i
    if firstOne > -1 and lastOne > -1:
        print(Counter(s[firstOne:lastOne])['0'])
    else:
        print(0)
