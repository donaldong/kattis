def rl
  STDIN.readline
end

rl
days = rl.split.map &:to_i
days.sort!.reverse!
max_day = 0
for i in 0...days.size
  max_day = [max_day, i + 2 + days[i]].max
end
puts max_day
