from math import factorial as F

n = int(input())
for _ in range(n):
  k = int(input())
  print(F(k) % 10)
