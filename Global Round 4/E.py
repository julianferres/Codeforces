from collections import deque

s = input()
left = deque([])
right = deque([])


def solve():
	l,r = 0, len(s)
	while(l<=r):
		if(r-l == 0):
			print("".join(left+right))
			return 
		elif(r-l <= 3):
			print("".join(left+deque([s[l]])+right))
			return 
		
		if('a' in s[l:l+2] and 'a' in s[r-2:r]):
			left.append('a')
			right.appendleft('a')
		elif('b' in s[l:l+2] and 'b' in s[r-2:r]):
			left.append('b')
			right.appendleft('b')
		else:
			left.append('c')
			right.appendleft('c')
		
		l+=2
		r-=2

solve()

