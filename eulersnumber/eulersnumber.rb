require 'bigdecimal'

LIM = 1e14.to_i
F = Array.new(10001)
F[0] = 1
for i in 1...F.size
  F[i] = i * F[i - 1]
  break if F[i] > LIM
end

n = $stdin.readline.to_i
res = BigDecimal.new(0)
for i in 0..n
  res += BigDecimal.new(1) / F[i]
  break if F[i] > LIM
end
printf("%.14f\n", res)
