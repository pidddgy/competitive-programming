#!python3

import random
import sys
A = input()
A = list(A)
for i in range(20):
    random.shuffle(A)
    b = ''.join(A)
    if(b[0] == '0'): continue
    if(int(b) % 7 == 0):
        print(b)
        sys.exit(0)

print(0)