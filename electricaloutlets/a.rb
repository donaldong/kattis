n = $stdin.readline
n.to_i.times do
  k, *o = $stdin.readline.split.map &:to_i
  puts (o.reduce(&:+) - k + 1)
end
