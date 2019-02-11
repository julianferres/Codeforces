def cnt(x , l , r):
	#Devuelve el indice mayor i tal que a[i]<=x
	if(l == r):
		return l
	else:
		half = (l+r-1)//2
		return cnt(x,a,half) if x<a[half] else cnt(x,half+1,r)

def rec(l , r):
	if(l==r):
		return A if l not in a else B
	l_i , r_i = cnt(r,0,k-1) , cnt(l,0,k-1)
	x = r_i - l_i + 1

	if(x==0): return A
	else:
		burn = B*(r-l+1)*x
		half = (r+l-1)//2
		return min(burn, rec(l,half) + rec(half+1,r))


n , k , A , B = map( int , input().split() )
a = sorted([int(x) for x in input().split()])
print(rec(1,2**n))

#Va a dar TLE (por ser O(n*k^2) )