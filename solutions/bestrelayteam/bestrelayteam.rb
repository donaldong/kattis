class Runner
  attr_accessor :name, :first, :rest
  def initialize(name, first, rest)
    @name = name
    @first = first
    @rest = rest
  end
end

def total_time(runner, rests)
  res = runner.first
  rests.each do |rest|
    res += rest.rest
  end
  res
end

STDIN.readline
min_time = 1e9 
runners = []
STDIN.each_line do |line|
  tokens = line.split
  runners << Runner.new(
    tokens[0],
    tokens[1].to_f,
    tokens[2].to_f,
  )
end

best_team = nil

runners.each do |first|
  rests = []
  runners.each do |rest|
    next if first == rest 
    rests << rest 
  end
  rests.sort_by! do |rest|
    rest.rest
  end
  rests = rests.first(3)
  t = total_time(first, rests)
  if t < min_time
    min_time = t
    best_team = [first] + rests
  end
end

puts "%.9f" % min_time
best_team.each do |runner|
  puts runner.name
end
