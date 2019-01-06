import itertools
import re

N = int(input())
aqt = input()
total = 0
cute = set()
for combo in [''.join(l) for i in range(N) for l in itertools.combinations(aqt, i+1)]:
    if(aqt.startswith(combo) and aqt.endswith(combo)):
        cute.add(combo)

for thing in cute:
    total += len(re.findall(r'(?=(%s))' % re.escape(thing), aqt))

print(total)
