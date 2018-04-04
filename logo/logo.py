from math import *

T = int(input())
for _ in range(T):
    N = int(input())
    theta = 0
    x = 0
    y = 0
    for _ in range(N):
        tokens = input().split()
        cmd, v = tokens[0], int(tokens[1])
        if cmd == 'lt':
            theta += v / 180 * pi
        elif cmd == 'rt':
            theta -= v / 180 * pi
        elif cmd == 'fd':
            x += cos(theta) * v
            y += sin(theta) * v
        else:
            x -= cos(theta) * v
            y -= sin(theta) * v
    print(round(sqrt(x * x + y * y)))
