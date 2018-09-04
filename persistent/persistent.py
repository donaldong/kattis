def solve(n):
    if n == 0: return 10
    if n < 10: return n + 10
    D = [0] * 10
    for i in range(9, 1, -1):
        while n % i == 0:
            D[i] += 1
            n //= i
    if n != 1: return -1
    res = 0
    for i in range(10):
        while D[i] > 0:
            res *= 10
            res += i
            D[i] -= 1
    return res

while True:
    num = int(input())
    if num == -1: break
    res = solve(num)
    if res < 0: print('There is no such number.')
    else: print(res)
