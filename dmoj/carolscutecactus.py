# https://dmoj.ca/problem/valentines18j4s1

import math

n, m = [int(num) for num in raw_input().split()]
middle = int(math.ceil((n + m) / 2))

higherNum = middle
lowerNum = middle

while str(higherNum) != str(higherNum)[::-1] and str(lowerNum) != str(lowerNum)[::-1]:
    higherNum += 1
    lowerNum -= 1

if str(higherNum) == str(higherNum)[::-1]:
    print(higherNum)
elif str(lowerNum) == str(lowerNum)[::-1]:
    print(lowerNum)
