F = [1]
for i in range(1, 101):
    F.append(F[-1] * i)
try:
    while True:
        word = input()
        count = {}
        for c in word:
            if c not in count:
                count[c] = 1
            else:
                count[c] += 1
        res = F[len(word)]
        for val in count.values():
            res //= F[val]
        print(res)
except:
    pass
