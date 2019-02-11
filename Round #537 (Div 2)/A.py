def A():
    vowels = "aeiou"
    a = input()
    b = input()
    if(len(a)!=len(b)):
        print("No")
    else:
        for i in range(len(a)):
            if((a[i] not in vowels and b[i] in vowels) or (a[i] in vowels and b[i] not in vowels)):
                print("No")
                return
        
        print("Yes")
    
    
A()