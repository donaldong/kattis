N, S = [int(x) for x in input().split()]
names = [None] * N
bets = [None] * N
for i in range(N):
  tokens = input().split()
  names[i] = tokens[0]
  bets[i] = int(tokens[1])
M = {}
M[0] = True
res = set()

def possible(n, k):
  if n in M: return M[n]
  if n < 0 or k < 0: return False
  if possible(n - bets[k], k - 1):
    M[n] = True
    res.add(k)
    return True
  if possible(n, k - 1):
    M[n] = True
    return True
  return False

possible(S, N - 1)
print(len(res))
for r in res:
  print(names[r])
