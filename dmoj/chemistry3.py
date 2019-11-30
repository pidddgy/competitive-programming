#!python3
import math
N = int(input())
M = int(input())

def dec(beakers, cups):
    comb = 2**beakers
    return (cups+comb-1) // comb

for m in range(132832198372187129879):
    poss = N
    for i in range(M):
        poss = dec(m, poss)
        if(poss is 1):
            break
    
    if(poss is 1):
        print(m)
        break