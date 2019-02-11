import sys

m1=0
m2=0

for _ in range(int(input())):
    d , h , w = sys.stdin.readline().split()
    h , w = int(h) , int(w)

    if (d=='+'):
        m1 = max( min(h,w) , m1)
        m2 = max( max(h,w), m2)
    
    else:
        print("YES") if ((h>=m1 and w>=m2) or (h>=m2 and w>=m1)) else print("NO")