DIR = [[-1,0],[1,0],[0,-1],[0,1]]

def solve(grid, num_row, num_col)
  steps = 0
  player = []
  fire = []
  (0...num_row).each do |i|
    (0...num_col).each do |j|
      case grid[i][j]
      when '@'
        player << [i, j]
      when '*'
        fire << [i, j]
      end
    end
  end
  until player.empty?
    _fire = []
    _player = []
    fire.each do |r, c|
      DIR.each do |dr, dc|
        r2, c2 = r + dr, c + dc
        next if r2 < 0 || r2 >= num_row || c2 < 0 || c2 >= num_col
        next unless ['.', '@'].include?(grid[r2][c2])
        grid[r2][c2] = '*'
        _fire << [r2, c2]
      end
    end
    fire = _fire
    steps += 1
    player.each do |r, c|
      DIR.each do |dr, dc|
        r2, c2 = r + dr, c + dc
        return steps if r2 < 0 || r2 >= num_row || c2 < 0 || c2 >= num_col
        next unless grid[r2][c2] == '.' # only step in to a room
        grid[r2][c2] = '@'
        _player << [r2, c2]
      end
    end
    player = _player
  end
  'IMPOSSIBLE'
end

gets.to_i.times do
  c, r = gets.split(' ').map(&:to_i)
  grid = r.times.map { gets.chomp }
  puts solve(grid, r, c)
end
