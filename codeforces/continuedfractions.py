#!python3

from decimal import *
from fractions import Fraction
p, q = map(int, input().split())
n = int(input())
a = list(map(int, (input().split())))

a = [0]+a;

ans = Fraction(1, a[n])
for i in range(n-1, 0, -1):
    ans += a[i]
    ans = Fraction(1, ans);

# print(Fraction(q, p))
# print(ans)
if(Fraction(q, p) == ans):
    print("YES")
else:
    print("NO")