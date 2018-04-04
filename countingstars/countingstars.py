# BFS

from collections import deque

def search(G):
    for r in range(len(G)):
        for c in range(len(G[r])):
            if G[r][c] == '-':
                return r, c
    return -1, -1

DR = [-1, 1, 0, 0]
DC = [0, 0, -1, 1]
t = 1
while True:
    try:
        R, C = [int(x) for x in input().split()]
        G = [None] * R
        for i in range(R):
            G[i] = list(input())
        y, x = search(G)
        count = 0
        while x >= 0 and y >= 0:
            Q = deque()
            Q.append((y, x))
            G[y][x] = '#'
            while len(Q):
                r, c = Q.popleft()
                for i in range(4):
                    nr = r + DR[i]
                    nc = c + DC[i]
                    if 0 <= nr < R and 0 <= nc < C:
                        if G[nr][nc] == '-':
                            G[nr][nc] = '#'
                            Q.append((nr, nc))
            count += 1
            y, x = search(G)
        print("Case {}: {}".format(t, count))
        t += 1
    except EOFError:
        break

