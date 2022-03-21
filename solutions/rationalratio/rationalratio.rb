num, k = $stdin.readline.split
toks = num.split '.'
k = k.to_i
x = toks.last.size + 1
y = toks.last.size - k + 1
b = 10 ** x - 10 ** y
a = (toks.last[0, x - 1].to_i - toks.last[0, y - 1].to_i) * 10
puts a.to_r / b + toks.first.to_i
