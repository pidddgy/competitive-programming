#!python3

N, K = map(int, input().split())
s = input();

have = input().split();
flatten = lambda l: [item for sublist in l for item in sublist]

for x in have:
    s = s.split(x)
    flatten(s)

for x in s:
    print(x)