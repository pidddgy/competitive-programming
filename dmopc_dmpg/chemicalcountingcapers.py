import sys
input = sys.stdin.readline
from collections import deque, Counter


N = input()
s = input().split()

MOD = 1000000007

multiplier = 1
cnt = Counter()
elems = set()
mult = deque()

for elem in s[::-1]:
    if elem is ")":
        continue
    
    elif elem is "(":
        multiplier = multiplier//mult.pop()
    
    elif elem.isdigit():
        mult.append(int(elem))
        multiplier *= int(elem)
    
    else:
        if elem not in cnt:
            cnt[elem] = 0

        cnt[elem] += multiplier
        cnt[elem] %= MOD
        elems.add(elem)

        multiplier //= mult.pop()
    

elems = sorted(elems)

for a in elems:
    print(a + " " +str((cnt[a]) % MOD))