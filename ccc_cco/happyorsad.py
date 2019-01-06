# https://dmoj.ca/problem/ccc15j2

thing = input()
h = thing.count(':-)')
s = thing.count(':-(')

if h == 0 and s == 0:
    print('none')
elif h == s:
    print('unsure')
elif h > s:
    print('happy')
elif s > h:
    print('sad')
