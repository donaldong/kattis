n = int(input())
total = 0
for i in range(1, n + 1):
    s = str(i)
    for c in s:
        total += int(c)
print(total)
