def solve(y, p)
  if y[-1] == 'e'
    "#{y}x#{p}"
  elsif %(a i o u).split.include?(y[-1])
    "#{y[0...-1]}ex#{p}"
  elsif y[-2..-1] == 'ex'
    y + p
  else
    y + 'ex' + p
  end
end

puts solve(*$stdin.readline.split)
