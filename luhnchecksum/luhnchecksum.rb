def rl
  $stdin.readline.chomp
end

def solve(n)
  n *= 2
  return n if n < 10
  n / 10 + n % 10
end

rl.to_i.times do
  n = rl
  chars = n.chars.reverse
  tot = 0
  for i in 0...chars.size
    if i % 2 == 0
      tot += chars[i].to_i
    else
      tot += solve chars[i].to_i
    end
  end
  puts tot % 10 == 0 ? "PASS" : "FAIL"
end
