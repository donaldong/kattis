def rl
  STDIN.readline.split.map &:to_i
end

n = rl.last
N = rl
r = N.last.to_r
-2.downto(-n) { |i| r = N[i] + 1 / r }
puts r
