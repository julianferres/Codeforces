n , k = map(int, input().split())
d = [int(x) for x in input().split()]

cnt = {i:0 for i in range(k)}
for i in d:
    cnt[i%k]+=1
amnt = cnt[0]//2
for i in range(1,k//2):
    amnt += min(cnt[i],cnt[(k-i)%k])

if(k>1):
    if(not k%2):
        amnt += cnt[k//2]//2
    else:
        amnt += min(cnt[k//2],cnt[(k-k//2)%k])

print(2*amnt)
