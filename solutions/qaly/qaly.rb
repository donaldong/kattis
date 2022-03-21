def rl
  STDIN.readline
end

n = rl.to_i
res = 0.0
n.times {
  nums = rl.split.map &:to_f
  res += nums[0] * nums[1]
}
printf("%.7f\n", res)
