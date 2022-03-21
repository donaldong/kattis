def rl
  STDIN.readline.split.map &:to_i
end

DR = [-1, 1, 0, 0]
DC = [0, 0, -1, 1]
R, C, N = rl
G = Array.new(R) { Array.new(C, false) }
q = Queue.new
N.times do
  r, c = rl
  r -= 1
  c -= 1
  q << [r, c]
  G[r][c] = true
end
q << [nil, nil]
count = 1
loop do
  r, c = q.pop
  if r.nil?
    break if q.empty?
    count += 1
    q << [nil, nil]
    next
  end
  for dr, dc in DR.zip(DC)
    nr = r + dr
    nc = c + dc
    next unless (0...R).include?(nr) && (0...C).include?(nc)
    next if G[nr][nc]
    q << [nr, nc]
    G[nr][nc] = true
  end
end
puts count
