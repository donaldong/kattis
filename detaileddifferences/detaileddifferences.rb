t = STDIN.readline.to_i
for j in 0...t
  a = STDIN.readline.chomp
  b = STDIN.readline.chomp
  puts a, b
  for i in 0...a.size
    putc a[i] == b[i] ? '.' : '*'
  end
  puts '', ''
end
