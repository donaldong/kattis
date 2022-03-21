require 'set'

def rl 
  STDIN.readline
end

t = rl.to_i
for _t in 0...t
  n = rl.to_i
  s = Set.new
  for _n in 0...n
    s.add rl
  end
  puts s.size
end
