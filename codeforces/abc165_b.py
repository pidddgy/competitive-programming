#!python3

import math

x = int(input())

cur = 100
y = 0

while cur < x:
    cur = math.floor(cur * 1.01)
    # print(cur)
    y += 1

print(y)
