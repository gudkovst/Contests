n = int(input())
days = set()
for i in range(n):
    d, c, s = map(int, input().split())
    days |= {day for day in range(d+c, s+1)}
if len(days) >= n:
    print("YES")
else:
    print("NO")

