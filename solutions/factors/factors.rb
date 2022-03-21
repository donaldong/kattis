def is_prime(n)
  i = 3
  while i * i <= n
    return false if n % i == 0
    i += 2
  end
  true
end

def F(n)
  res = 1
  for i in 2..n
    res *= i
  end
  res
end

def ways
  res = F(S.sum)
  for s in S
    res /= F(s)
  end
  res
end

P = [2]
LIM = 2 ** 63
tot = 2
cur = 3
while tot < LIM
  if is_prime(cur)
    tot *= cur
    P << cur
  end
  cur += 2
end

RES = Hash.new(LIM)
S = []

def dfs(i, k, l, v)
  v *= P[i] ** k
  return if v >= LIM
  S << k
  w = ways()
  RES[w] = [RES[w], v].min
  for j in 1..k
    dfs(i + 1, j, l, v)
  end
  S.pop
end

for i in 1..63
  dfs(0, i, 0, 1)
end

for line in $stdin.each_line
  n = line.to_i
  puts "#{n} #{RES[n]}"
end
