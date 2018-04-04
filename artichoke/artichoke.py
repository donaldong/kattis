# Function

from math import *

p, a, b, c, d, n = [int(x) for x in input().split()]
f = lambda x: p * (sin(a * x + b) + cos(c * x + d) + 2)
max_val = f(1)
res = 0
for x in range(2, n + 1):
    y = f(x)
    if y > max_val:
        max_val = y
    res = max(res, max_val - y)
print(res)
