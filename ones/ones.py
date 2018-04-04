def build(n):
    res = ''
    for i in range(n):
        res += '1'
    return res

for num in range(1, 100000):
    if num % 2 == 0 or num % 5 == 0:
        continue
    l = len(str(num))
    cur = build(l)
    while int(cur) % num != 0:
        cur += '1'
    print(len(cur))

