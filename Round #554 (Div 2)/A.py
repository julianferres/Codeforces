n , m = map(int , input().split())
a = [int(x)%2 for x in input().split()]
b = [int(x)%2 for x in input().split()]

pares_a , pares_b = 0 , 0
impares_a , impares_b = 0,0
for i in a:
    if(i%2): impares_a+=1
    else: pares_a+=1

for i in b:
    if(i%2): impares_b+=1
    else: pares_b+=1

print(min(impares_a,pares_b)+min(pares_a,impares_b))
