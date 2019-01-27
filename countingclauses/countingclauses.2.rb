def rl
  STDIN.readline.split.map &:to_i
end

M, N = rl
puts M >= 8? "satisfactory" : "unsatisfactory"
