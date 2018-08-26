line = input()
res = 1
r = 1
for c in line:
    if c == 'L':
        res *= 2
    elif c == 'R':
        res = res * 2 + r
    else:
        res =  2 * res * (1 + r)
        r *= 3
print(res)
