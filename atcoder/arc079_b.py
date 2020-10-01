#!python3

k = int(input())

for n in range(1, 51):
    x = n-1-k;
    y = (n-1)+(k*n)

    if x >= 1 and y >= 1:
        print(n)
        print(y, end = " ")
        for i in range(n-1):
            print(x, end = " ")
        print()
        break