#!python3

import math

def lcm(a, b):
    return a*b // (math.gcd(a, b))

n = int(input())

print(lcm(n, lcm(max(1, n-1), max(1, n-2))))