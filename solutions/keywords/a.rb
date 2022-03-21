n = gets.to_i
puts (n.times.map {gets.gsub('-', ' ').downcase}.uniq.size)
