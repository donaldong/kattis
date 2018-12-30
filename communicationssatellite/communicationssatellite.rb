Point = Struct.new(:x, :y, :r, :p, :rank)
Edge = Struct.new(:a, :b, :w)

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

def find(n)
  return n.p if n.p == n
  n.p = find(n.p)
end

def join(a, b)
  if a.rank < b.rank
    a.p = b
  elsif b.rank < a.rank
    b.p = a
  else
    b.p = a
    a.rank += 1
  end
end

N = rl[0]
P = Array.new(N)
for i in 0...N
  x, y, r = rl
  P[i] = Point.new(x, y, r, nil, 0)
  P[i].p = P[i]
end

E = Array.new(N * (N - 1) / 2)
k = 0
for i in 1...N
  for j in 0...i
    E[k] = Edge.new(j, i, cost(P[j], P[i]))
    k += 1
  end
end

res = 0.0
DS = Array.new(N, -1)
E.sort_by! { |e| e.w }
for e in E
  ra = find(P[e.a])
  rb = find(P[e.b])
  next if ra == rb
  join(ra, rb)
  res += e.w
end
printf("%.7f\n", res)
