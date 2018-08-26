line = input()
res = 1
r = 1
for c in line:
    if c == 'P':
        continue
    elif c == 'L':
        res *= 2
    elif c == 'R':
        res = res * 2 + r
    else:
        t = 2 * res
        res += 2 * t + r
        r *= 3
print(res)
