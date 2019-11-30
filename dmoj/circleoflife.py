#!python3
import math
N = 0
T = 0

def cntBit(n):
    return math.log2(n)+1

out = ""

def tobin(n):
    global out
    if(n//2 is not 0):
        tobin(n//2)
    
    out = out + str(n%2)

def tf(s):
    r = 0
    r = 0
    l = s << 1
    r = s >> 1
    if s & (1 << (N-1)):
        l ^= 1
        l ^= 1 << N
    
    if s & 1:
        r ^= 1 << (N-1)
    
    return l ^ r


N, T = map(int, input().split())

inp = input()

s = int(inp, 2)

pattern = []
for i in range(0, T):
    s = tf(s)

    pattern.append(s)
    if(len(pattern)%2 is 0):
        incr = len(pattern)//2
        same = True

        for j in range(0, len(pattern)//2):
            if(pattern[j] is not pattern[j+incr]):
                same = False
                break
        
        if same:
            rem = (T-len(pattern)) % (len(pattern)/2)
            for j in range(0, int(rem)):
                s = tf(s)
            
            tobin(s)
            while(len(out) is not N): out = "0"+out
            print(out)
            exit(0)

tobin(s)
while(len(out) is not N): out = "0"+out
print(out)