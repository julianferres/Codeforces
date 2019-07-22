n = int(input())
a = [int(x) for x in input().split()]

chosen = a[0]
chosen_idx = [1]
suma = sum(a)


for i in range(n):
	if(a[i]<=a[0]//2):
		chosen+=a[i]
		chosen_idx.append(i+1)
	if(chosen*2>suma):
		break #Ya me arme lo que necesitaba

if(chosen*2> suma):
	print(len(chosen_idx))
	print(*chosen_idx)

else:
	print(0)
