def harshad(n)
  digits = n.to_s.chars.map &:to_i
  sd = digits.inject(0, :+)
  n % sd == 0
end

n = STDIN.readline.to_i
until harshad(n)
  n += 1
end
puts n
