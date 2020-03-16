#!python

import sys
input = sys.stdin.readline


import math

N, Q = map(int, input().split())

def eucdis(a, b):
    if(a is 0 and b is 0):
        return 0
    elif(a is 0):
        return b;
    elif b is 0:
        return a
    else:
        A = abs(a*a)
        B = abs(b*b)
        return abs(math.sqrt(A+B))
        

# print(eucdis(3, 5))
pfi = [];
pse = [];
dis = [];
for i in range(N):
    x, y = map(int, input().split())
    pfi.append(abs(x));
    pse.append(abs(y));

for i in range(N):
    dis.append(eucdis(pfi[i], pse[i]))

dis.sort()


for i in range(Q):
    R = int(input())
    l = 0;
    r = N-1
    lastgood = 0
    shit = False
    while l <= r:
        m = (l+r)//2
        if(dis[m] <= R):
            l = m+1;
            lastgood = m;
            shit = True
        else:
            r = m-1;
    
    if not shit:
        print(0)
    else:
        print(lastgood+1)