
DX = []
DY = []
for x in -2018..2018
  for y in -2018..2018
    if x * x + y * y == 2018 ** 2
      DX << x
      DY << y
    end
  end
end
p DX
p DY
