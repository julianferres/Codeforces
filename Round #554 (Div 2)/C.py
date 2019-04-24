import math
def divisors(n):
    div = []
    d = 1
    while(d**2<=n):
        if(not n%d):
            div.append(d)
            if(d**2!=n):
                div.append(n//d)
        d+=1
    return div

def lcm(x, y):
   """This function takes two
   integers and returns the L.C.M."""
   lcm = (x*y)//math.gcd(x,y)
   return lcm

def C():
    a , b = map(int , input().split())
    a , b = min(a,b) , max(a,b)
    if(not b%a):
        print(0)
        return
    divs = divisors(b-a)
    M = b*a
    k = 0
    for d in divs:
        aux_k = d*math.ceil(b/d)-b
        if(lcm(a+aux_k,b+aux_k)<M):
            M = lcm(a+aux_k,b+aux_k)
            k = aux_k
    print(k)


C()
