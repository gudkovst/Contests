t = int(input())
for q in range(t):
    n = int(input())
    a = map(int, input().split())

    if sum(a) >= 2 * (n - 1):
        print("yes")
    else:
        print("no")
