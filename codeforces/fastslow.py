import os

thing = 0
while 1:
    thing += 1
    os.system('./generator > input.txt')
    os.system('./softstrategies < input.txt > slow.txt')
    os.system('./1194D < input.txt > output.txt')
    if open('slow.txt').read() != open('output.txt').read():
            print('WA')
            exit(0)
    print("AC random test "+str(thing))