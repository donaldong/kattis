def rl
  $stdin.readline.chomp
end

def fix(n)
  while n < 0
    n += 26
  end
  (n + 97).chr
end

n, m = rl.split.map &:to_i
tail = rl.chars.reverse
B = rl.chars.reverse
A = Array.new(m)
for i in 0...n
  A[i] = tail[i]
end
for i in 0...(m - n)
  A[i + n] = fix(B[i].ord - A[i].ord)
end
puts A.join('').reverse
