#!python3

import math

T = int(input())

for tc in range(T):
    n = int(input())

    sides = 2*n

    x = math.tan(math.radians(180/sides))
    a = 1/(2*x)

    y = math.sin(math.radians(180/sides))
    b = 1/(2*y)

    print(b+b)
