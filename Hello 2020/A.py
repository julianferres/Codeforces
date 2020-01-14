n, m = map(int, input().split())
s = input().split()
t = input().split()

q = int(input())

for _ in range(q):
    y = int(input())
    print(s[(y-1)%len(s)]+t[(y-1)%len(t)])


