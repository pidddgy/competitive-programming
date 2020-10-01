#!python3

a, b = input().split()

ma = int(max(str(a)+str(b)))

ans = 0
for i in range(int(ma)+1, 37):
    sum = str(int(a, i)+int(b, i))
    print(sum)
    sum = int(sum, i)
    
    # ans = max(ans, len(str(sum)))

print(ans)