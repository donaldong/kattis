def solve(n):
    res = 1
    for i in range(2 * n, n, -1):
        res *= i
    for i in range(2, n + 2):
        res //= i
    return res

n = int(input())
for _ in range(n):
    k = int(input())
    print(solve(k))
