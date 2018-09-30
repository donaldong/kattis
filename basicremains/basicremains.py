def to_dec(n, b):
  res = 0
  for digit in n:
    res *= b
    res += int(digit)
  return res

def print_base(n, b):
  if n == 0:
    print(0)
    return
  D = []
  while n > 0:
    D.append(n % b)
    n //= b
  for d in reversed(D): print(d, end='')
  print()

while True:
  line = input()
  if line == '0': break
  b, p, m = line.split()
  b = int(b)
  x = to_dec(p, b)
  y = to_dec(m, b)
  print_base(x % y, b)
