l = Array.new(2, Array.new(2))
d = Array.new(2, Array.new(2))
N = gets.chomp.to_i
v = gets.chomp.to_i
l[0][0] = l[0][1] = 1
d[0][0] = d[0][1] = v
1.upto(N - 1) {
  v = gets.chomp.to_i

  if v > d[0][1] && l[0][1] + 1 > l[0][0]
    l[1][0] = l[0][1] + 1
    d[1][0] = v
  elsif v > d[0][1] && l[0][1] + 1 == l[0][0]
    l[1][0] = l[0][0]
    d[1][0] = [d[0][0], v].max
  else
    l[1][0] = l[0][0]
    d[1][0] = l[1][0] == 1 ? [d[0][0], v].max : d[0][0]
  end

  if v < d[0][0] && l[0][0] + 1 > l[0][1]
    l[1][1] = l[0][0] + 1
    d[1][1] = v
  elsif v < d[0][0] && l[0][0] + 1 == l[0][1]
    l[1][1] = l[0][1]
    d[1][1] = [d[0][1], v].min
  else
    l[1][1] = l[0][1]
    d[1][1] = l[1][1] == 1 ? [d[0][1], v].min : d[0][1]
  end

  d[0], d[1] = d[1], d[0]
  l[0], l[1] = l[1], l[0]
}
puts l[0].max
