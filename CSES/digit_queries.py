def findNthDigit(n: int) -> int:
	if n < 10:
		return n
	i = 0
	count = 0
	num = 1
	while True:
		next = ((9 * (i + 1)) * num)
		i += 1
		if count + next >= n:
			break
		num *= 10
		count += next
	count += 1
	move, digit = divmod(n - count, i)
	count += move * i
	num += move

	return int(str(num)[digit])


tc = int(input())
for _ in range(tc):
    n = int(input())
    print(findNthDigit(n))
