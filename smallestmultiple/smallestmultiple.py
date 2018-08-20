def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

try:
    while True:
        N = [int(x) for x in input().split()]
        res = 1
        for n in N:
            res = lcm(res, n)
        print(res)
except EOFError:
    pass
