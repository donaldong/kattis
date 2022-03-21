res = []
$stdin.readlines.each_with_index do |l, i|
  res << i + 1 if l.include?('FBI')
end
puts res.empty? ? "HE GOT AWAY!" : res.join(' ')
