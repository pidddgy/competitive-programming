#!python3

a = int(input(), 2)

i = 0
ans =0
while True:
    if 4**i < a:
        ans += 1
    else:
        break
    i += 1

print(ans)