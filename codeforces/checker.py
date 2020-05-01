import os

thing = 0
while 1:
    thing += 1
    os.system('./generator > input.txt')
    os.system('./editorial < input.txt > bruteforce.txt')
    os.system('./906a < input.txt > fast_solution.txt')
    if open('bruteforce.txt').read() != open('fast_solution.txt').read():
            print('WA')
            exit(0)
    print("AC random test "+str(thing))