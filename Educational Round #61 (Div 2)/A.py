def A():
    cnt1 = int(input())
    cnt2 = int(input())
    cnt3 = int(input())
    cnt4 = int(input())

    if(cnt4!=cnt1):
        print(0)
        return
    if(cnt3>0 and cnt1==cnt4==0):
        print(0)
        return
    print(1)
A()
