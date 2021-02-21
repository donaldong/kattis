$stdin.readline
as = $stdin.readlines
res = 0
(0...(as.size - 1)).each do |i|
  res += 1 if as[i] == as[i + 1]
end
puts res
