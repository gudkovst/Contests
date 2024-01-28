class Dragon():

    def __init__(self, a, b, n):
        self.n = n
        self.a = a
        self.b = b
        self.friends = list()
        self.mark = False

    def add_friend(self, dr):
        self.friends.append(dr)

    def get(self):
        if self.mark:
            return 0, 0
        self.mark = True
        i, g = self.a, self.b
        for f in self.friends:
            a, b = f.get()
            i += a
            g += b
        return i, g
    

n, m, g = map(int, input().split())
ar = map(int, input().split())
br = list(map(int, input().split()))
dragons = list()
for i, a in enumerate(ar):
    dragons.append(Dragon(a, br[i], i))
for i in range(m):
    u, v = map(int, input().split())
    dragons[u-1].add_friend(dragons[v-1])
    dragons[v-1].add_friend(dragons[u-1])
inters = 0
for dr in dragons:
    i, gw = dr.get()
    if (0 <= gw <= g) and (i > inters >= 0):
        inters = i
print(inters)
