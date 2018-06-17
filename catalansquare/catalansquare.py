n = int(input())
n += 1
F = [1] * (n * 2 + 1)
for i in range(2, len(F)):
    F[i] = F[i - 1] * i
res = F[2 * n]
res //= F[n] * F[n] * (n + 1)
print(res)
