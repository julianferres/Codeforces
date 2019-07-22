def modexp ( x, y, p ):
   ans = 1
   while y != 0:
      if y & 1:
         ans = (ans * x)%p
      y >>= 1
      x = (x * x)%p;
   return ans

M = 998244353

n, m = map(int, input().split())

print(modexp(2,n+m,M))