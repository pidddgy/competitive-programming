#!python3

import sys
input = sys.stdin.readline

# Python3 implementation to Set  
# bits in the given range 
  
# Function to toggle bits 
# in the given range 

def setallbitgivenrange(n, l, r): 
  
    # calculating a number 'range' 
    # having set bits in the range 
    # from l to r and all other 
    # bits as 0 (or unset). 
    range = (((1 << (l - 1)) - 1) ^  
                ((1 << (r)) - 1)) 
  
    return (n | range) 
  
# Driver code 
s, m = map(int, input().split())

S = int(input(), 2)
for i in range(m):
    l, r = map(int, input().split())
    # print(s-l+1)
    # print(s-r+1)
    S = setallbitgivenrange(S,  s-r+1, s-l+1)
    print(S)
    # print()

# This code is contributed by Anant Agarwal. 
