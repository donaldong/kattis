def readint
  $stdin.readline.to_i
end

n = readint
nums = n.times.map { readint }
j = 0
good_job = true
(1..nums.last).each do |i|
  num = nums[j]
  if num == i
    j += 1
    next
  end
  puts i
  good_job = false
end
puts "good job" if good_job
