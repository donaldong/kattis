def readline
  $stdin.readline
end

def incongruousity(row, rows)
  max_res = 0
  rows.each_with_index do |row2, i|
    res = 0
    row.zip(row2).each do |a, b|
      res += 1 unless a == b 
    end
    max_res = res if res > max_res
  end
  max_res
end

readline
n = readline.to_i
as = n.times.map do
  readline.split(', ')
end

min_score = 101
res = []
as.each do |row|
  score = incongruousity(row, as)
  if score < min_score
    res = [row]
    min_score = score
  elsif score == min_score
    res << row
  end
end

res.each { |row| puts row.join(', ')}
