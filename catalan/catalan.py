def solve(n):
    res = 1
    n2 = n * 2
    for i in range(n):
        res *= n2 - i
        res //= i + 1
    return res // (n + 1)

n = int(input())
for _ in range(n):
    k = int(input())
    print(solve(k))
