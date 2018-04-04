n, s, k = [int(x) for x in input().split()]
if n < k:
    print(0)
if n >= 500:
    print(1)
else:
    F = [1]
    for i in range(1, 501):
        F.append(F[-1] * i)
    C = [1]
    while len(C) <= s:
        __C = [1]
        for i in range(1, len(C)):
            __C.append(C[i - 1] + C[i])
        __C.append(1)
        C = __C
    C2 = [1]
    while len(C2) <= n:
        __C = [1]
        for i in range(1, len(C2)):
            __C.append(C2[i - 1] + C2[i])
        __C.append(1)
        C2 = __C
    result = 0
    for i in range(1, k):
        result += C[i] * F[i] * C2[n - i + 1]
    d = 1
    for i in range(n):
        d *= s
    print(1 - (result / d))
