Pt = Struct.new(:x, :y)

def dist(a, b)
  dx = a.x - b.x
  dy = a.y - b.y
  Math.sqrt(dx * dx + dy * dy)
end

def pos(o, a, b, c, d)
  return 0 if o.x <= a.x && o.y >= a.y
  return 1 if (a.x...b.x).include?(o.x) && o.y > a.y
  return 2 if o.x >= b.x && o.y >= b.y
  return 3 if (c.y...b.y).include?(o.y) && o.x > b.x
  return 4 if o.x >= c.x && o.y <= c.y
  return 5 if (a.x...b.x).include?(o.x) && o.y < c.y
  return 6 if o.x <= c.x && o.y <= c.y
  7
end

nums = $stdin.readline.split.map &:to_i
o = Pt.new(nums[0], nums[1])
d = Pt.new(nums[2], nums[3])
b = Pt.new(nums[4], nums[5])
a = Pt.new(d.x, b.y)
c = Pt.new(b.x, d.y)
res = nil
case pos(o, a, b, c, d)
when 0
  res = dist(o, a)
when 1
  res = o.y - a.y
when 2
  res = dist(o, b)
when 3
  res = o.x - b.x
when 4
  res = dist(o, c)
when 5
  res = c.y - o.y
when 6
  res = dist(o, d)
when 7
  res = a.x - o.x
end
printf("%.5f\n", res)
