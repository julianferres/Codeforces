T = int(input())
for _ in range(T):
    x = input(); y = input()
    last1y = 0
    for i in range(len(y)-1,-1,-1):
        if(y[i]=='1'):
            break
        last1y+=1
    last1x = last1y
    for j in range(len(x)-1-last1y,-1,-1):
        if(x[j]=='1'):
            break
        last1x+=1
    print(last1x-last1y)
