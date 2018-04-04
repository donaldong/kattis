# Coord

from math import *

def dist_x(a, b, m, r):
    dx = a - b
    return abs(dx) / m * pi * r

def dist_y(dy, n, r):
    return r / n * abs(dy)

nums = input().split()
M, N, R = int(nums[0]), int(nums[1]), float(nums[2])
ax, ay, bx, by = [int(x) for x in input().split()]
a = (ax, ay)
b = (bx, by)
res = None
dist = lambda p1, p2: dist_x(p1[0], p2[0], M, dist_y(min(p1[1], p2[1]), N, R)) + dist_y(p1[1] - p2[1], N, R)
for y in range(N + 1):
    for x in range(M + 1):
        c = (x, y)
        if res is None:
            res = dist(a, c) + dist(c, b) 
        else:
            res = min(res, dist(a, c) + dist(c, b))
print("%.7f" % res)

