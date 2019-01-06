def backtracking(rotations , suma):

	if(not len(rotations)):
		return suma == 0

	a = backtracking(rotations[:-1] , (suma+rotations[-1])%360 )

	b = backtracking(rotations[:-1] , (suma-rotations[-1])%360 )

	return (a or b)

def B():

	n = int(input())

	rotations = [int(input()) for i in range(n)]

	print("YES" if backtracking(rotations,0) else "NO")

B()