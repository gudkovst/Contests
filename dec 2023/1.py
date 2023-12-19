name = list("TINKOFF")
t = int(input())
for q in range(t):
    inp = list(input())
    flag = True
    for s in name:
        if s not in inp:
            print("no")
            flag = False
            break
    if flag:
        if len(inp) != len(name):
            print("no")
        else:
            print("yes")
        
