require 'set'

def rl
  $stdin.readline.split.map &:to_i
end

N, K = rl
pkms = Array.new(N)
for i in 0...N do
  a, d, h = rl
  pkms[i] = [i, a, d, h]
end

s = Set.new
for i in 1..3 do
  pkms.sort_by! { |v| -v[i] }
  for j in 0...K do
    s << pkms[j][0]
  end
end

puts s.size
