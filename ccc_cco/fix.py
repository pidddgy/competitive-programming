# https://dmoj.ca/problem/ccc04s1

N = int(input())
for i in range(N):
    hasFix = False
    a = input()
    b = input()
    c = input()
    if a.startswith(b) or a.startswith(c) or a.endswith(b) or a.endswith(c):
        hasFix = True
    if b.startswith(a) or b.startswith(c) or b.endswith(a) or b.endswith(c):
        hasFix = True
    if c.startswith(a) or c.startswith(b) or c.endswith(a) or c.endswith(b):
        hasFix = True
    if hasFix:
        print("No")
    else:
        print("Yes")

