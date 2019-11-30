#!python3
import sys
import random
#thanks stack overflow
def solve(x,y):
    x = abs(x)
    y = abs(y)
    if y > x:
        temp=y
        y=x
        x=temp  
    if (x==2 and y==2):
        return 4
    if (x==1 and y==0):
        return 3

    if(y == 0 or float(y) / float(x) <= 0.5):
        xClass = x % 4
        if (xClass == 0):
            initX = x/2
        elif(xClass == 1):
            initX = 1 + (x/2)
        elif(xClass == 2):
            initX = 1 + (x/2)
        else:
            initX = 1 + ((x+1)/2)

        if (xClass > 1):
            return initX - (y%2)
        else:
            return initX + (y%2)
    else:
        diagonal = x - ((x-y)/2)
        if((x-y)%2 == 0):
            if (diagonal % 3 == 0):
                return (diagonal/3)*2
            if (diagonal % 3 == 1):
                return ((diagonal/3)*2)+2
            else:
                return ((diagonal/3)*2)+2
        else:
            return ((diagonal/3)*2)+1


X, Y, H, V = map(int, input().split())

T = int(input())
# print(solve(2, 2))
for i in range(0, min(600, H-1)):
    for j in range(0, min(600, V-1)):
        if(solve(X+i, Y+j) < T):
            print("YES")
            sys.exit()

print("NO")