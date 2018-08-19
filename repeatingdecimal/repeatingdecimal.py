def power(a, b):
    if b == 0:
        return 1
    res = power(a, b // 2)
    if b % 2 == 0:
        return res * res
    return res * res * a

try:
    while True:
        a, b, c = [int(x) for x in input().split()]
        a *= power(10, c) 
        a //= b
        print("0.{}".format(a))
except EOFError:
    pass
