USED = Array.new(6, false)
$count = 0

def valid(seq)
  n = 0
  seq.each do |d|
    n = n * 10 + d
  end
  return false unless (L..H).include?(n)
  seq.each do |d|
    return false if n % d != 0
  end
  true
end

def dfs(n, seq)
  USED[n] = true
  seq << n
  if seq.size == 6
    $count += 1 if valid(seq)
  else
    for i in 1..9
      dfs(i, seq) unless USED[i]
    end
  end
  USED[n] = false
  seq.pop
end

L, H = $stdin.readline.split.map &:to_i
for n in 1..9
  dfs(n, [])
end
puts $count
