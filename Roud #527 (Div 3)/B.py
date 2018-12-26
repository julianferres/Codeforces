def B():

	n = int(input())

	skills = [int(x) for x in input().split()]
	skills.sort()

	problems_to_solve = 0

	for i in range(n):
		problems_to_solve += (-1)**(i+1)*skills[i]

	print(problems_to_solve)
	
B()