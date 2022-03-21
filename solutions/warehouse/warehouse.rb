def rl
  STDIN.readline
end

T = rl.to_i
T.times {
  f = Hash.new(0)
  n = rl.to_i
  n.times {
    n, c = rl.split
    f[n] += c.to_i
  }
  puts f.size
  f.sort_by { |k, v| [-v, k]}.each { |k, v| puts "#{k} #{v}" }
}
