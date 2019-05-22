def _binsearch(lista, x, l , r):
	"""Recursive binsearch between l and r index in lista"""

	#Couldn't find x in lista
	if(r<l): return -1 

	mid = (l+r)//2
	if(lista[mid]  == x): return mid
	
	return _binsearch(lista, x, l , mid-1) if(x<lista[mid]) else _binsearch(lista, x, mid+1, r)

def binsearch(l, element):
	"""Wrapper of recursive binsearch"""
	return _binsearch(l, element , 0 , len(l)-1)



