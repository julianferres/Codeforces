
i = [0]
N = int(input())
estado = ["A"] * N
print(i[0], estado)

def hanoi(X, Y, Z, N):
    if(N <= 0): return
    hanoi(X, Z, Y, N-1)
    estado[N-1] = Y
    i[0] += 1
    print(i[0], estado)
    hanoi(Z, Y, X, N-1)


hanoi("A", "B", "C", N)
