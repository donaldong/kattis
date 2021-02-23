$stdin.readline
ds = $stdin.readline.split.map(&:to_i)
res = Array.new(ds.size)
res[0] = 1
ds.each_with_index do |d, i|
  res[d + 1] = i + 2
end
puts res.join(' ')
