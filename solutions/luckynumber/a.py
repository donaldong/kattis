#!/usr/bin/python3
#
# @author      Donald Dong
# @date        2022-03-21
# @tags        math
# @difficulty  1500
# 
n = int(input())
nums = list(range(1,10))
for i in range(2,n+1):
  nums2 = []
  for num in nums:
    for d in range(10):
      num2 = num*10+d
      if num2%i == 0:
        nums2.append(num2)
  nums = nums2
print(len(nums))
