def rl
  STDIN.readline.chomp
end

t, A, B = [rl.to_i, rl, rl]
f = A.size - t
same = 0
for a, b in A.chars.zip(B.chars)
  same += 1 if a == b 
end
diff = A.size - same
puts [same, t].min + [diff, f].min
