from math import inf

def solve(i2, i3, i5, i7, i11, i13, i17, i19):
    return pow(2, i2) * pow(3, i3) * pow(5, i5) * pow(7, i7) * pow(11, i11) * pow(13, i13) * pow(17, i17) * pow(19, i19)

def main():
    ans = [inf]*1005
    for i1 in range(1000):
        print(i1)
        for i2 in range(32):
            for i3 in range(20):
                for i4 in range(6):
                    for i5 in range(4):
                        for i6 in range(4):
                            for i7 in range(3):
                                for i8 in range(3):
                                    k = (i1+1)*(i2+1)*(i3+1)*(i4+1)*(i5+1)*(i6+1)*(i7+1)*(i8+1)
                                    aux = solve(i1, i2, i3, i4, i5, i6, i7, i8)
                                    if(aux != -1 and k <= 1002): ans[k] = min(ans[k],aux)

    print(ans)

main()
