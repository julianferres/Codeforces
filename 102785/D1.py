with open("entrada.txt", "r") as f:
    lines = f.readlines()
    for i in range(len(lines)):
        lines[i] = lines[i].strip()

    cum = ""
    for line in lines:
        cum += line

    cum = cum.split(",")
    for i in range(len(cum)):
        cum[i] = cum[i].replace(" ", "")

    print(cum)
