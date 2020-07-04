n = int(input())
a = [int(x) for x in input().split()]

inv = []

for i in range(n):
    for j in range(i+1,n):
        if a[j] < a[i]:
            inv.append((i,-a[j],j))

inv.sort()
print(inv)