def readints
  $stdin.readline.split.map(&:to_i)
end

s, t, n = readints
ds = readints
bs = readints
cs = readints

ds.each_with_index do |d, i|
  s += d
  if i < bs.size
    c = cs[i]
    s = c * (1 + s / c + s % c == 0 ? 0 : 1)
    s += bs[i]
  end
end
puts s <= t ? "yes" : "no"
