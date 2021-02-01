#!python3

import os

x = 0
while 1:
    x += 1
    os.system('./generator > input.txt')
    os.system('./dmopc20c3p4 < input.txt > output.txt')
    os.system('./slow < input.txt > slow.txt')

    if open('slow.txt').read() != open('output.txt').read():
        print("WA")
        exit(0)
    print("AC random test "+str(x))
