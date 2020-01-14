from collections import Counter
n = int(input())
s = input()
L = Counter(s)['L']
R = Counter(s)['R']
print(R-(-L)+1)
