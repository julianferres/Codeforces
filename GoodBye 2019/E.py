
n = int(input())
p = []

def contar_paridades(p):
    oo,oe,eo,ee = 0,0,0,0
    for x,y in p:
        if x&1 and y&1:
            oo+=1
        elif x&1:
            oe+=1
        elif y&1:
           eo+=1
        else:
            ee+=1
    return ee,eo,oe,oo

def todas_en_una(p):
    ee,eo,oe,oo = contar_paridades(p)
    not_null = bool(ee)+bool(eo)+bool(oe)+bool(oo)
    return not_null == 1


for i in range(n):
    x,y = map(int, input().split())
    p.append([x,y])

while todas_en_una(p):
    for i in range(n):
        p[i][0]//=2; p[i][1]//=2

ee,eo,oe,oo = contar_paridades(p)
if ee and oo and not eo and not oe:
    print(ee)
    ans = [i+1 for i in range(n) if not p[i][0]&1]
    print(*ans)

elif not ee and not oo and eo and oe:
    print(eo)
    ans = [i+1 for i in range(n) if not p[i][0]&1]
    print(*ans)

else:
    print(ee+oo)
    ans = [i+1 for i in range(n) if not (p[i][0]+p[i][1])&1]
    print(*ans)
