s = input()
difs = [(int(s[i])-int(s[i-1]))%10 for i in range(1,len(s))]

out = [[None]*10 for _ in range(10)]

dist = [[[None]*10 for _ in range (10)] for __ in range(10)]

for i in range(10):
    for j in range(10):
        for d in range(10):
            if(d==0):
                dist[i][j][d] = 0
                continue
            ijd = 100
            for x in range(10):
                for y in range(10):
                    if((d-(i*x+j*y))%10 == 0):
                        ijd = min(ijd,x+y-1)
            if(ijd == 100):
                dist[i][j][d] = -1
            else:
                dist[i][j][d] = ijd

for i in range(10):
	for j in range(10):
		print(dist[i][j][3])
for i in range(10):
    for j in range(10):
        cum = 0
        for d in difs:
            if dist[i][j][d]==-1:
                cum = -1
                break
            cum+= dist[i][j][d]
        out[i][j] = cum

for fila in out:
    print(*fila)
