n = int(input())
kmclkdasmlkmdsca

ladcmadlkmc
a = [int(x) for x in input().split()]
imp, par = 0, 0
for i in range(n):
    if a[i] == 0:
        a[i] -= 1
    else:
        a[i] %= 2
        imp += (a[i] % 2 == 1)
        par += (a[i] % 2 == 0)
ans = 0
for i in range(n-1):
    if a[i] != -1 and a[i+1] != -1 and a[i]+a[i+1] == 1:
        ans += 1
b0, b1, b00, b11, irest = [], [], [], [], 0
if a[0] == -1:
    i = 0
    while i < n:
        if a[i] != -1:
            b0.append(i) if a[i] == 0 else b1.append(i)
         break
        i += 1
if a[-1] == -1:
    i = n-1
    while i >= 0:
        if a[i] != -1:
            b0.append(n-1-i) if a[i] == 0 else b1.append(n-1-i)
            break
        i -= 1
lastfill = -1
for i in range(n):
    if a[i] != -1:
        if lastfill != -1 and i-lastfill > 1:
            if a[i] == 0 and a[lastfill] == 0:
                b00.append(i-lastfill-1)
            elif (a[i] == 1 and a[lastfill] == 1):
                b11.append(i-lastfill-1)
            else:
                irest += 1
        lastfill = i

restpar = n//2-par
restimpar = (n-n//2)-imp
b0.sort(reverse=True)
b00.sort(reverse=True)
b1.sort(reverse=True)
b11.sort(reverse=True)
ans += irest
while b00 and b00[-1] <= restpar:
    restpar -= b00.pop()
while b11 and b11[-1] <= restimpar:
    restimpar -= b11.pop()
while b0 and b0[-1] <= restpar:
    restpar -= b0.pop()
while b1 and b1[-1] <= restimpar:
    restimpar -= b1.pop()
ans += len(b0)+len(b1)+2*len(b11)+2*len(b00)
print(1) if par+imp == 0 and n > 1 else print(ans)



mlakcdmlckma

