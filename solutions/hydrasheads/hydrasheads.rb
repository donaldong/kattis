MAX_SIZE = 101
# [h, t] => moves
DP = Array.new(MAX_SIZE) { Array.new(MAX_SIZE, -1) }

def step(q, h, t, k)
  return if h < 0 || t < 0
  return if h >= MAX_SIZE || t >= MAX_SIZE
  return unless DP[h][t] == -1
  DP[h][t] = k
  q << [h, t, k]
end

def fill 
  q = Queue.new
  q << [0, 0, 0]
  until q.empty?
    h, t, k = q.pop
    k += 1
    step(q, h, t - 1, k)
    step(q, h + 2, t, k)
    step(q, h - 1, t + 2, k)
  end
end

fill
$stdin.each_line do |line|
  h, t = line.split.map &:to_i
  break if h == 0 && t == 0
  puts DP[h][t]
end
