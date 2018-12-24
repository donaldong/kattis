def rl
  STDIN.readline
end

def check(set, f)
  a, b = set.sort
  return -1 if b > 6 && b - a > 2
  if (b - a >= 2 && b >= 6) \
    || (f && a == 6 && b == 7)
    return set[0] > set[1] ? 0 : 1
  end
  -1
end

def valid(players, sets)
  k = -1
  players.each_with_index do |player, i|
    k = i if player == 'federer'
  end
  counts = Array.new(2, 0)
  sets.each_with_index do |set, j|
    i = check(set, j <= 1)
    return false if i < 0
    return false unless k < 0 || i == k
    counts[i] += 1
    return false if counts[i] == 2 \
      && j + 1 != sets.size
  end
  counts.max == 2
end

players = rl.split
n = rl.to_i
n.times do
  sets = rl.split.map do |set|
    set.split(':').map &:to_i
  end
  puts valid(players, sets) ? 'da' : 'ne'
end
