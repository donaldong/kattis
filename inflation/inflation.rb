def rl
  STDIN.readline.split.map &:to_i
end

f = true
n = rl[0]
C = rl.sort
min = 1.0
for i in 0...n
  if C[i] > i + 1
    f = false
    break
  end
  min = [min, C[i].to_f / (i + 1)].min
end
if f
  printf("%.7f\n", min)
else
  puts "impossible"
end
