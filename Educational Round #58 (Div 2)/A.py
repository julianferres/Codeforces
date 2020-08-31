import math
def A():
    
    q = int(input())
    
    for i in range(q):
        l , r , d = map( int , input().split() )
        
        if(d<l):
            print(d)
            continue
        if not r%d:
            print( (r//d + 1) * d )
            continue
        
        print( math.ceil(r/d)*d )
        
        
A()