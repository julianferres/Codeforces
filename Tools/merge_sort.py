def merge_sort(lista):
	"""Sort a list with Merge sort algorithm.
	Pre: list with comparable elements.
	Post: ordered list."""

	if len(lista) < 2:
		return lista

	mid = len(lista) // 2
	return merge( merge_sort(lista[:mid]), merge_sort(lista[mid:]))

def merge(list1, list2):
	"""Merge two ordered lists into an output ordered list."""
	index1, index2 = 0, 0
	output_list = []

	while(index1 < len(list1) and index2 < len(list2)):
		if (list1[index1] < list2[index2]):
			output_list.append(list1[index1])
			index1 += 1
		else:
			output_list.append(list2[index2])
			index2 += 1
	output_list += list1[index1:]
	output_list += list2[index2:]

	return output_list

print(merge([1,3,5],[]))
print(merge_sort([2,3,4,62,1,4,773,1,5]))
