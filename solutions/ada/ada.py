# Brute Force
nums = [int(x) for x in input().split()]
nums.pop(0)
N = [n for n in nums]
d = None
stable = False
T = []
while not stable and len(N) > 0:
    stable = True
    M = []
    for i in range(1, len(N)):
        diff = N[i] - N[i - 1]
        if diff != 0:
            stable = False
        M.append(diff)
    T.append(N[-1])
    N = M
print(len(T) - 1, sum(T))
