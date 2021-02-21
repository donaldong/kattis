s = $stdin.readline
res = 0
s.split(';').each do |tok|
  ts = tok.split('-')
  if ts.size == 2
    res += ts[1].to_i - ts[0].to_i + 1
  else
    res += 1
  end
end
puts res
