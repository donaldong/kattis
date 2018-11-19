t = 1
print = Proc.new { |s| printf s }
while true
  n = STDIN.readline.to_i
  break if n == 0
  puts "SET #{t}"
  t += 1
  lists = Array.new(2) { Array.new }
  for i in 0...n
    lists[i % 2] << STDIN.readline
  end
  lists[0].each &print
  lists[1].reverse_each &print
end
