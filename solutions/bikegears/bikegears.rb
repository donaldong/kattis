Gear = Struct.new(:f, :b, :r)

def rl
  $stdin.readline.split.map &:to_i
end

n, m = rl
F = rl
B = rl
G = []
for f in F
  for b in B
    G << Gear.new(f, b, f.to_r / b)
  end
end
G.sort_by! { |g| [g.r, g.f] }
for g in G
  puts "(#{g.f},#{g.b})"
end
