#!python3

for i in range(5000000, 6000001):
    if(str(i) == str(i)[::-1]):
        print(i)