def print_row(i, t)
  t.times { putc "." }
  putc B[i]
  (A.size - 1 - t).times { putc "." }
  puts
end

A, B = $stdin.readline.split.map &:chars
r, c = nil
for i in 0...A.size
  r = B.index(A[i])
  next if r.nil?
  c = A.index(B[r])
  break
end

for i in 0...r
  print_row(i, c)
end
puts A.join('')
for i in (r + 1)...B.size
  print_row(i, c)
end
