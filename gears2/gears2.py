# Graph
# DFS

class Node:
    def __init__(self, x, y, r):
        self.x = x
        self.y = y
        self.r = r
        self.neigh = []
        self.length = None
        self.f = False

def connected(a, b):
    dx = a.x - b.x
    dy = a.y - b.y
    r = a.r + b.r
    return dx * dx + dy * dy == r * r

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def solve(cur, tar, length, res):
    if cur.length is None:
        cur.length = length
    elif cur.length % 2 != length % 2:
        return False
    if cur == tar:
        res[0] = length
        return True
    cur.f = True
    for n in cur.neigh:
        if n.f:
            continue
        if not solve(n, tar, length + 1, res):
            return False
    cur.f = False
    return True

def display(a, b, same):
    r = gcd(a, b)
    a = a // r
    b = b // r
    if same:
        print(b, a)
    else:
        print(b, -a)
    
N = int(input())
gears = [None] * N 
for i in range(N):
    x, y, r = [int(n) for n in input().split()]
    gears[i] = Node(x, y, r)
    for j in range(i):
        if connected(gears[i], gears[j]):
            gears[j].neigh.append(gears[i])
            gears[i].neigh.append(gears[j])
res = [None]
if solve(gears[0], gears[-1], 1, res):
    if res[0] is None:
        print(0)
    else:
        display(gears[0].r, gears[-1].r, res[0] % 2 != 0)
else:
    print(-1)
