lang = Hash.new "eh"
STDIN.each_line do |line|
  line.chomp!
  break if line.empty?
  tokens = line.split
  lang[tokens.last] = tokens.first
end
STDIN.each_line do |line|
  line.chomp!
  puts lang[line]
end
