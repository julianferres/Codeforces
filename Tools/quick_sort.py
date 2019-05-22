def classifierUsingPivot ( l, pivot ):
	lessThanPivot, pivots, greaterThanPivot = [] , [] , []
	for element in l:
		if(element < pivot): lessThanPivot.append(element)
		elif(element == pivot): pivots.append(element)
		else: greaterThanPivot.append(element)
	return lessThanPivot, pivots, greaterThanPivot
		

def quicksort( l ):
	if( len(l) <= 1 ): return l
	a , b , c = classifierUsingPivot(l, l[0])
	return quicksort(a) + b + quicksort(c)

