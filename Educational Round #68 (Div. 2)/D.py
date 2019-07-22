T = int(input())
A = "Alice"
B = "Bob"
for _ in range(T):
    n, k = map(int,input().split())

    if(n==0):
        print(B)

    elif(k%3!=0):
        print(B) if(n%3==0) else print(A)

    else:
        if(n%(k+1)%3==0 and n%(k+1)!=k):
            print(B)
        else:
            print(A)
