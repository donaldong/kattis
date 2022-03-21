def rl
  $stdin.readline.split
end

n, s = rl.map &:to_i
items = Array.new(n)
for i in 0...n
  a, b = rl
  items[i] = [b.to_i, a]
end
items.sort!

res = []
(n-1).downto(0) do |i|
  if s >= items[i][0]
    s -= items[i][0]
    res << i
  end
end

res.clear unless s == 0
puts res.size
for r in res
  puts items[r][1]
end
