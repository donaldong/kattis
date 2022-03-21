def rl
  STDIN.readline.chomp
end

N = rl.to_i
N.times {
  rl
  pos = {}
  cnt = Hash.new(0)
  str = rl
  str.chars.each_with_index do |c, i|
    pos[c] = i
    cnt[c] += 1
  end

  res = 0
  str.chars.each_with_index do |c, i|
    res += pos[c] - i
  end
  cnt.each do |_, v|
    res -= (v - 1) * v / 2
  end
  puts res * 5
}
