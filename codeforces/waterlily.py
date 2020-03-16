#!python3

# bool trng(ld a, ld b, ld c) 
# { 
#     if (a + b <= c or a + c <= b or b + c <= a) 
#         return false; 
#     else
#         return true; 
# } 
import math
def trng(a, b, c):
    if (a + b <= c or a + c <= b or b + c <= a):
        return False; 
    else:
        return True; 


H, L = map(int, input().split())
x = 0
base = math.sqrt((H*H)+(L*L))
while(not trng(x, x, base)):
    x += 0.000001

print(x)