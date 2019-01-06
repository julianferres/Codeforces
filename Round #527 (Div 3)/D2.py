def D2old():

	n = int(input())
	
	bricks = input().split()
	bricks = [int(x) for x in bricks]

	m = min(bricks)
	M = max(bricks)

	while(m!=M):

		for idx in range(n):
			if(bricks[idx] != m): continue

			m_count = 0

			while( idx+m_count < n and bricks[idx+m_count]== m):
				bricks[idx+m_count] +=1
				m_count+=1

			if(m_count%2):
				print("NO")
				return

			m_count = 0

			m = min(bricks)
			break

	print("YES")

D2old()

# Daba TLE en test 12 