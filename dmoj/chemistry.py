#!python3

N = int(input())

for i in range(10000000):
    if(2**i >= N):
        print(i)
        break
