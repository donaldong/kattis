def rl
  STDIN.readline.split.map &:to_i
end

def solve(n)
  (1 + n) * n / 2 + n
end

rl[0].times do
  k, n = rl
  puts "#{k} #{solve n}"
end
