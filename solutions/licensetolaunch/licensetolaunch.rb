def rl 
  STDIN.readline
end

rl
nums = rl.split.map &:to_i
puts nums.each_with_index.min[1]
