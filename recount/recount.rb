counts = Hash.new(0)
STDIN.each_line do |line|
  break if line == "***"
  counts[line] += 1
end
max_counts = counts.values.max
winners = counts.select { |k, v| v == max_counts }
if winners.size != 1
  puts "Runoff!"
else
  puts winners.first[0]
end
