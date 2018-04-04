import math

while True:
    n = int(input())
    if n == 0:
        break
    nums = input()
    if n <= 2:
        print(1)
    else:
        print(math.factorial(n - 2) // 2)
        
