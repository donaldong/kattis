import sys

MAX_W = 6301

for line in sys.stdin:
  if line[0] == '0':
    break
  V = [int(x) for x in line.split()]
  n = V[0]
  tot = sum(V[1:])
  DP = [[tot] * MAX_W for _ in range(n + 1)]
  for i in range(1, n + 1):
    for w in range(1, MAX_W):
      DP[i][w] = min(DP[i][w - 1], DP[i - 1][w])
      if w >= V[i]:
        sel = DP[i - 1][w - V[i]] - 2 * V[i]
        if sel >= 0:
          DP[i][w] = min(DP[i][w], sel)
  s = 0
  w = MAX_W - 1
  for i in range(n, 0, -1):
    while w != 0 and DP[i][w - 1] == DP[i][w]:
      w -= 1
    if w < V[i] or DP[i][w] == DP[i - 1][w]:
      continue
    print(DP[i][:w+1])
    s += V[i]
    w -= V[i]
  print("%d %d" % (tot - s, s))
