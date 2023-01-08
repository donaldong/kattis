#!/usr/bin/python3
#
# @author      Donald Dong
# @date        2023-01-07
# @tags        dp, input format
# @difficulty  1400
#
n = int(input())
for _ in range(n):
  *ab, c, d = [int(v) for v in input().split()]
  A = ab[::2]
  B = ab[1::2]
  DP = dict()

  def f(x,y):
    if not (x > 0 and y > 0):
      return d
    if (x,y) in DP:
      return DP[(x,y)]
    res = c
    for a, b in zip(A, B):
      res += f(x-a, y-b)
    DP[(x,y)] = res
    return res

  xy = [int(v) for v in input().split()]
  X = xy[::2]
  Y = xy[1::2]
  for x,y in zip(X, Y):
    print(f(x, y))
  print()
