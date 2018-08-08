# https://dmoj.ca/problem/valentines18j2
n = input()
x, y = [int(num) for num in raw_input().split()]
totalClaps = 0
articlesNeeded = 0

while totalClaps < n and x > 0:
    totalClaps += 2*x
    x -= y
    articlesNeeded += 1

if x <= 0:
    print('RIP')
else:
    print(articlesNeeded)

