def A():
    q = int(input())
    for i in range(q):
        n , a , b  = map(int , input().split())
        if(2*a<b): 
            print(n*a)
            continue
        else:
            print(n//2*b+(n%2)*a)
            
A()
