def bfs(g, start)
  q = [start]
  g[start[0]][start[1]] = "."
  while !q.empty?
    cur = q.shift
    $dir.each {
      |dr|
      $dir.each {
        |dc|
        next if dr == 0 && dc == 0
        r = cur[0] + dr
        c = cur[1] + dc
        next unless 0 <= r && r < $m && 0 <= c && c < $n
        next if g[r][c] != "#"
        g[r][c] = "."
        q << [r, c]
      }
    }
  end
end

def remove(g)
  for i in 0...$m do
    for j in 0...$n do
      next if g[i][j] != "#"
      bfs(g, [i, j])
      return true
    end
  end
  false
end

def solve(g)
  res = 0
  while remove(g)
    res += 1
  end
  res
end

$dir = [-1, 0, 1]
tokens = gets.chomp.split(" ")
$m = tokens[0].to_i
$n = tokens[1].to_i
g = Array.new($m)
for i in 0...$m do
  g[i] = gets.chomp
end
puts solve(g)
