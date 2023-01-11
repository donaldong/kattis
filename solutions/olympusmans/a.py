#
#  @date        2023-01-10
#  @tags        geometry, binary search
#  @difficulty  1500
#
from fractions import Fraction as frac
n = int(input())
H = [int(v) for v in input().split()]
max_h_i = max(range(n), key=H.__getitem__)
if max_h_i == 0:
  print(0)
else:
  min_slope = frac(H[max_h_i]-H[0],max_h_i)
  min_slope_i = 0
  for i in range(1, max_h_i):
    slope = frac(H[max_h_i]-H[i],max_h_i-i)
    if slope < min_slope:
      min_slope = slope
      min_slope_i = i

  m = frac(H[max_h_i]-H[min_slope_i], max_h_i-min_slope_i)
  b = H[max_h_i]-m*max_h_i-H[0]
  lo = int(-1e12)
  hi = 0
  while lo <= hi:
    x = (lo+hi)//2
    y = m*x+b
    if y < 4:
      lo = x+1
    else:
      hi = x-1
  print(-lo+1)
