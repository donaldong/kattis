Point = Struct.new(:x, :y, :r)

def rl
  $stdin.readline.split.map &:to_i
end

def dist(a, b)
  dx = a.x - b.x
  dy = a.y - b.y
  Math.sqrt(dx * dx + dy * dy)
end

def cost(a, b)
  dist(a, b) - a.r - b.r
end

N = rl[0]
P = Array.new(N)
for i in 0...N
  x, y, r = rl
  P[i] = Point.new(x, y, r)
end

res = 0.0
vis = Array.new(N, false)
D = Array.new(N, 1e9)
cur = 0

for i in 1...N
  vis[cur] = true
  min = 1e9
  min_index = 0
  for n in 1...N
    next if vis[n]
    D[n] = [D[n], cost(P[n], P[cur])].min
    if D[n] < min
      min = D[n]
      min_index = n
    end
  end
  cur = min_index
  res += min
end

printf("%.7f\n", res)
