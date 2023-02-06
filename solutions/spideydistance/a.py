#
#  @date        2023-02-05
#  @tags        counting
#  @difficulty  1500
#

from math import floor
from fractions import Fraction as frac

t,s = [int(i) for i in input().split()]
tcount = 0
scount = 0
tdiag = 0
sdiag = 0
tdist = 2
sdist = frac(3,2)

while sdist <= s:
  sremain = s-sdist
  tremain = t-tdist
  sdiag += 1
  if tremain >= 0:
    tdiag += 1
    tcount += min(tremain, floor(sremain))
  scount += floor(sremain)
  tdist += 2
  sdist += frac(3,2)

tcount = 8*tcount + 4*(tdiag+min(t,s)) + 1
scount = 8*scount + 4*(sdiag+s) + 1
print(frac(tcount,scount))
