import os

while 1:
        print("testing")
        os.system('python3 generator.py > input.txt')
        os.system('python3 slow.py < input.txt > bruteforce.txt')
        os.system('./perica < input.txt > fast_solution.txt')
        if open('bruteforce.txt').read() != open('fast_solution.txt').read():
                print('WA')
                exit(0)