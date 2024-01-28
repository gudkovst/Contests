inp = input().split('code')
print(inp[0], end="")

for part in inp[1:]:
    k = 0
    for symb in part:
        if symb.isdigit():
            k += 1
        else:
            break
    if k:
        print("???", end="")
    print(part[k:], end="")
