F = [1]
for i in range(1000000):
    F.append(F[-1] * (i + 1))
    print(i, len(str(F[i + 1])))
