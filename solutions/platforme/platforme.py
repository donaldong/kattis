def possible(p, x):
    if x is None or p[1] is None or p[2] is None:
        return True
    return p[1] <= x <= p[2]

N = int(input())
P = [None] * N
for i in range(N):
    P[i] = [int(x) for x in input().split()]
P.sort(key=lambda x: x[0], reverse=True)
P.append([0, None, None])
res = 0
for i in range(len(P)):
    for j in range(i + 1, len(P)):
        if possible(P[j], P[i][1] + 0.5):
            res += P[i][0] - P[j][0]
            break
    for j in range(i + 1, len(P)):
        if possible(P[j], P[i][2] - 0.5):
            res += P[i][0] - P[j][0]
            break
print(res)
