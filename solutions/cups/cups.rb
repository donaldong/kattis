def rl
  STDIN.readline
end

def parse(line)
  ts = line.split
  c = ts[0][0].ord
  return ts[1], ts[0].to_i if ('0'.ord..'9'.ord).cover? c
  [ts[0], ts[1].to_i * 2]
end

cups = Array.new(rl.to_i) { parse rl }
cups.sort_by! { |p| p.last }
cups.each { |p| puts p.first }
