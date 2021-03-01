c, n, m = gets.split.map &:to_i
cows = n.times.map { gets.to_i }

res = Array.new(51, 0)
farms = Array.new(n, 1)
(0..50).each do |d|
  (0...n).each do |i|
    if cows[i] <= c
      res[d] += 1
      cows[i] *= 2
    else
      farms[i] *= 2
      res[d] += farms[i]
    end
  end
end

m.times.each { puts res[gets.to_i] }
