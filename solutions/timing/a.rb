def solve(a, g, nodes)
  res = nodes[a]
  nodes[a] = nil

  g[a].each do |b, _|
    next unless nodes[b]
    res += solve(b, g, nodes) 
  end
  res
end

t = $stdin.readline.to_i
t.times do
  n, l, t = $stdin.readline.split.map(&:to_i)
  nodes = $stdin.readline.split.map(&:to_f)
  g = n.times.map { [] }
  l.times.each do
    a, b, r = $stdin.readline.split
    a = a.to_i
    b = b.to_i
    r = r.to_f
    g[a] << [b, r]
    g[b] << [a, r]
  end
  (t + 1).times do
    new_nodes = [0.0] * n
    g.each_with_index do |e, a|
      e.each do |b, r|
        new_nodes[b] += r * nodes[a]
      end
    end
    nodes = new_nodes
  end
  p nodes

  min_score = Float::INFINITY
  (0...n).each do |i|
    score = solve(i, g, nodes.dup)
    min_score = [min_score, score].min
  end
  puts "%.8f" % min_score
end
