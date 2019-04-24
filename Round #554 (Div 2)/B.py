import math
def is_good(n):
    if(2**(int(math.log(n+1,2)))==n+1):
        return True
    return False

def B():
    n = int(input())
    if(is_good(n)):
        print(0)
        return
    p = []
    i = 1
    while(not is_good(n)):
        if(i%2):
            aux = bin(n)[2:]
            e = len(aux)-aux.index('0')
            p.append(e)
            n ^= 2**e-1
        else:
            n+=1
        i+=1

    print(i-1)
    print(*p)

B()
