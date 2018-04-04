def update(T, l, bottom):
    if bottom:
        T[0] += 1
        T[l] -= 1
    else:
        end = len(T) - 1
        T[end - l] += 1
        T[end] -= 1

N, H = [int(x) for x in input().split()]
T = [0] * (H + 1)
for i in range(N):
    update(T, int(input()), i % 2 == 0)
min_val = T[0]
for i in range(1, H):
    T[i] += T[i - 1]
    if T[i] < min_val:
        min_val = T[i]
count = 0
for i in range(0, H):
    if T[i] == min_val:
        count += 1
print(min_val, count)
