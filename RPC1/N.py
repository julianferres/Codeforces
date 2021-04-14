
import sys

def dame(a):
	dos, cinco = 0, 0
	while(a % 2 == 0):
		a //= 2
		dos += 1
	while(a % 5 == 0):
		a //= 5
		cinco += 1

	if(a == 1):
		return (dos, cinco)
	else:
		return (-1, -1)


def be(a, b):
    res = 1
    while (b > 0):
        if (b & 1):
            res = res * a
        a = a * a
        b >>= 1
    return res;


def main():
	#Leer de archivo
	for line in sys.stdin:
   		a, n = map(int, line.split())

   		ans = dame(a)

   		if(ans[0] == -1 and n > 0):
   		 	print("Precision Error")
   		else:
   			print(max(ans[0]*n, ans[1]*n), be(2,(max(ans)*n - ans[0]*n)) * be(5, (max(ans)*n - ans[1]*n)))

main()

