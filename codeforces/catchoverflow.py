#!python3
import sys
N = int(input())

cur = 1;
tot = 0;

lim = (2**32)-1
S = []
for i in range(N):
    inp = (input().split())
    if(len(inp) == 2):
        S.append(cur)
        cur *= int(inp[1])
    elif(inp[0] == "add"):
        tot += cur
        if(tot > lim):
            print("OVERFLOW!!!")
            sys.exit(0)
    else:
        cur = int(S[-1])
        S.pop();

print(int(tot))