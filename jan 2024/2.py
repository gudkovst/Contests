def dict_sort(d: dict) -> dict:
    return dict(sorted(d.items(), key=lambda item: item[1]))


n = int(input())
d = dict()
xr = map(int, input().split())
for x in xr:
    d[x] = d.get(x, 0) + 1
print(len(d))
d = dict_sort(d)
print(*d.values())


