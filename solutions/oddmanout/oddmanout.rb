def rl
  STDIN.readline
end

t = rl.to_i
for _t in 1..t
  rl
  nums = rl.split
  counts = Hash.new 0
  nums.each { |n| counts[n] += 1 }
  min_val = counts.min_by { |k, v| v }
  puts "Case ##{_t}: #{min_val.first}"
end
