from math import factorial

def c(n, m):
	if n < 0 or m < 0 or n < m: 
		return 0
	return factorial(n) // factorial(m) // factorial(n - m)


class MarbleDrawGame:
	def winningChance(self, marbles):
		total = sum(marbles)
		omega = c(total, 9)
		# print("omega", omega)

		favorables = 0
		for x in marbles:
			for tomo in range(5, x+1):
				if(tomo > 9):
					break
				favorables += c(x, tomo) * c(total - x, 9 - tomo)


		return favorables/omega

x = MarbleDrawGame()
print(x.winningChance([5, 5]))
print(x.winningChance([3, 4, 3]))
print(x.winningChance([1, 1, 1, 1, 1, 5]))
print(x.winningChance([3, 4, 5, 6]))
