def rl
  $stdin.readline.chomp
end

found = false
N = rl.to_i
N.times do
  k = rl.to_i
  name = rl
  has_peasoup = false
  has_pancakes = false
  k.times do
    food = rl
    if food == 'pea soup'
      has_peasoup = true
    elsif food == 'pancakes'
      has_pancakes = true
    end
  end
  if has_peasoup and has_pancakes
    puts name
    found = true
    break
  end
end
unless found
  puts 'Anywhere is fine I guess'
end
