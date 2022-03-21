P = [int(x) for x in input().split()]
P.insert(0, 0)
F = [0] * 100
for k in range(3):
    T = [int(t) - 1 for t in input().split()]
    F[T[0]] += 1
    F[T[1]] -= 1
res = F[0] * P[F[0]]
for i in range(1, 100):
    F[i] += F[i - 1]
    res += F[i] * P[F[i]]
print(res)

