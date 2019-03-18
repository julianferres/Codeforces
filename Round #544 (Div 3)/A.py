a , b = map(int , input().split(':'))
c , d = map(int , input().split(':'))

aux = (60*(a+c)+b+d)//2
print('{:02d}:{:02d}'.format((aux)//60,aux%60))
