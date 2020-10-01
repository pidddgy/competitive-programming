#!python3

for i in range(0, 8):
    print(bin(i).zfill(5).replace('b', ''))