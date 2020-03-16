#!python3

n, l, r = map(int, input().split())

print(n)
print(l)
print(r)

mi = 0
ma = 0

cur = 1

for i in range(n):
    print("cur is " + str(cur))

    ma += cur

    if not i+1 < r:
        cur *= 2
        print("HI")
        print("cur is now" + str(cur))
    

print(ma)
