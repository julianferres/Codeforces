from sys import stdout
from collections import defaultdict
def make_query(l):
    s = ["?"]
    for i in l:
        s.append(str(i))
    print(" ".join(s))
    stdout.flush()
    idx,element = map(int, input().split())
    
    return idx,element


n, k = map(int, input().split())
respuestas = defaultdict(int)
for j in range(1,k+2):
    idx,element = make_query([i for i in range(1,k+2) if i!=j])
    respuestas[(element,idx)]+=1

print("! {}".format(respuestas[max(respuestas)]))
stdout.flush()