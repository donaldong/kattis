count = Hash.new 0
cards = STDIN.readline.split.map { |x| count[x[0]] += 1 }
puts count.max_by { |k, v| v }.last
