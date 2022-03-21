def rl
  STDIN.readline.split.map &:to_i
end

N, Q = rl
D = rl
Q.times do
  type, a, b = rl
  if type == 1
    D[a - 1] = b
  else
    puts (D[a - 1] - D[b - 1]).abs
  end
end
