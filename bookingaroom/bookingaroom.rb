def rl
  STDIN.readline
end

r, n = rl.split.map &:to_i
used = Array.new(r, false)
for _n in 0...n
  e = rl.to_i - 1
  used[e] = true
end
all_used = true
for i in 0...r
  if !used[i]
    puts i + 1
    all_used = false
    break
  end
end
puts "too late" if all_used
