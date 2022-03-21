def readint
  $stdin.readline.split.map &:to_i
end

_, d = readint
as = readint
counts = Hash.new(0)
(0...as.size).each do |i|
  counts[as[i] / d] += 1
end

res = 0
counts.each do |_, count|
  res += count * (count - 1) / 2
end
puts res
