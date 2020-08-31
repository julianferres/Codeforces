from collections import Counter
q = int(input())

def isSubSequence(string1, string2, m, n):
    if m == 0:    return True
    if n == 0:    return False

    if string1[m-1] == string2[n-1]:
        return isSubSequence(string1, string2, m-1, n-1)
    return isSubSequence(string1, string2, m, n-1)

for _ in range(q):
    s = input()
    t = input()
    p = input()

    if((len(s)>len(t)) or (len(s)==len(t) and s!=t)):
        print("NO")
        continue

    d_s = Counter(s)
    d_t = Counter(t)

    d_p = Counter(p)

    posible = True
    for char in d_t:
        if(d_t[char]<d_s[char] or d_t[char]>d_s[char]+d_p[char]):
            posible = False

    if(posible==False):
        print("NO")
        continue

    if(isSubSequence(s,t,len(s),len(t))):
        print("YES")
    else:
        print("NO")
