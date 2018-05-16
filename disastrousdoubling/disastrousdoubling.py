n = input()
B = [int(x) for x in input().split()]
cur = 1
MOD = int(1e9 + 7)
f = True
for b in B:
    cur *= 2
    if cur < b:
        f = False
        break
    else:
        cur -= b
if f:
    print(cur % MOD)
else:
    print('error')
