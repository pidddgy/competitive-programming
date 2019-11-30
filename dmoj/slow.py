#!python3
import itertools
N, K = map(int, input().split())

a = [int(x) for x in input().split()]

ans = 0
for i in itertools.combinations(a, K):
    ans += max(i)

print(ans)