import math
def A():
    n = int(input())
    a  =  [int(x) for x in input().split()]
    pos , neg = 0 , 0
    for i in a:
        if(i>0): pos+=1
        if(i<0): neg+=1

    if(pos>= math.ceil(n/2)):
        print(1)
        return
    if(neg>= math.ceil(n/2)):
        print(-1)
        return
    print(0)
A()
