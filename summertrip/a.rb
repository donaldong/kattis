h = {}
s = $stdin.readline.chomp
(0...s.size).each do |i|
  c = s[i]
  h[c] ||= []
  h[c] << i
end
res = 0
h.keys.each do |a|
  h.keys.each do |b|
    next if a >= b
    src = nil
    x = h[a]
    y = h[b]
    i = 0
    j = 0
    # ooxxo
    # count for:
    #  ox
    #    xo
    while i < x.size && j < y.size
      if x[i] < y[j]
        if src != 1
          res += 1
          src = 1
        end
        i += 1
      else
        if src != 2
          res += 1
          src = 2
        end
        j += 1
      end
    end
  end
end
puts res
