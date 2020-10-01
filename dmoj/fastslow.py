#!python3

import os

thing = 0
while 1:
    thing += 1
    os.system('./generator > input.txt')
    os.system('./ccc20s4slow < input.txt > slow.txt')
    os.system('./ccc20s4 < input.txt > output.txt')
    if open('slow.txt').read() != open('output.txt').read():
            print('WA')
            exit(0)
    print("AC random test "+str(thing))