n, s, k = [int(x) for x in input().split()]
if n < k:
    print(0)
else:
    C = [1]
    while len(C) <= s:
        __C = [1]
        for i in range(1, len(C)):
            __C.append(C[i - 1] + C[i])
        __C.append(1)
        C = __C
    result = float(C[k])
    print(result)
    a = pow(2, n) - 2
    print(a)
    result *= a
    d = pow(s, n) 
    print(result / d)
