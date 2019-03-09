def rl
  $stdin.readline
end

def to_sec(s)
  tok = s.split(':').map &:to_i
  tok[0] * 60 + tok[1]
end

def update(sec)
  if $pt_a > $pt_b
    $t_a += sec - $t_prev 
  elsif $pt_a < $pt_b
    $t_b += sec - $t_prev 
  end
  $t_prev = sec
end

def display(sec)
  "%d:%02d" % [sec / 60, sec % 60]
end

N = rl.to_i
$pt_a = 0
$pt_b = 0
$t_a = 0
$t_b = 0
$t_prev = 0
N.times {
  tok = rl.split
  update(to_sec(tok.last))
  if tok[0] == 'H'
    $pt_a += tok[1].to_i
  else
    $pt_b += tok[1].to_i
  end
}
update(32 * 60)
puts "#{$pt_a > $pt_b ? 'H' : 'A'} #{display $t_a} #{display $t_b}"
