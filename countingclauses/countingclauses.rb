def rl
  STDIN.readline.split.map &:to_i
end

def eval_to_true(exp, n)
  puts "#{exp} #{n}"
  mask = 1
  for i in 0...N
    return true if (n & mask) == (exp & mask)
    mask <<= 1
  end
  false
end

def possible(exps)
  return false if exps.size < 8
  for n in 0...(1 << N)
    f = true
    exps.each do |exp|
      unless eval_to_true(exp, n)
        f = false
        break
      end
    end
    puts n
    return true if f
  end
  false
end

M, N = rl
exps = Array.new(M)
for i in 0...M
  nums = rl
  e = 0
  nums.each do |num| 
    e = (e << 1) + (num > 0 ? 1 : 0)
  end
  exps[i] = e
end

puts possible(exps) ? "satisfactory" : "unsatisfactory"
