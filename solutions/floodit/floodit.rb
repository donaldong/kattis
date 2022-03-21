$DR = [-1, 0, 0, 1]
$DC = [0, -1, 1, 0]

def bfs(g, col)
  return 0 unless g[0][0] == -1 || g[0][0] == col
  res = 1
  q = [[0, 0]]
  g[0][0] = -2
  while !q.empty?
    cur = q.shift
    for i in 0...4 do
      r = cur[0] + $DR[i]
      c = cur[1] + $DC[i]
      next unless 0 <= r && r < $size && 0 <= c && c < $size
      next unless g[r][c] == -1 || g[r][c] == col
      res += 1
      g[r][c] = -2
      q << [r, c]
    end
  end
  res
end

def step(grid)
  c = Array.new(6)
  for i in 0...6 do
    g = Array.new($size)
    for j in 0...$size do
      g[j] = grid[j].clone
    end
    c[i] = bfs(g, i)
  end
  max_val = c.max
  for i in 0...6 do
    return max_val, i if c[i] == max_val
  end
end

def solve(grid)
  moves = Array.new(6, 0)
  loop do
    count, col = step(grid)
    moves[col] += 1
    break if count == $size * $size
    bfs(grid, col)
    for i in 0...$size do
      for j in 0...$size do
        grid[i][j] = -1 if grid[i][j] == -2
      end
    end
  end
  moves[0] -= 1
  moves
end

t = gets.chomp.to_i
1.upto(t) do
  $size = gets.chomp.to_i
  grid = Array.new($size)
  for i in 0...$size do
    grid[i] = gets.chomp.each_char.map do |x|
      x.ord - '1'.ord
    end
  end
  moves = solve(grid)
  puts moves.sum
  moves.each do |move|
    print "#{move} "
  end
  print "\n"
end

