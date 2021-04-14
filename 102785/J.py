from re import fullmatch, compile

def solve():
    s = input()
    text = input()

    regex = compile(s)

    ans = regex.fullmatch(text)
    if(ans is not None):
        print("Yes")
    else:
        print("No")

solve()
