def rl
  STDIN.readline
end

def ssd(b, n)
  res = 0
  while n > 0
    res += (n % b) ** 2
    n /= b 
  end
  res
end

rl.to_i.times {
  k, b, n = rl.split.map &:to_i
  puts "#{k} #{ssd b, n}"
}
