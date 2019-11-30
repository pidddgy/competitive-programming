#!python3

def trng(n):
    return (n*(n+1))//2

maxans = 123213213213213132132131231231323123



T = int(input())
for i in range(T):
    M = int(input())
    # binary search for the term of the smallest traingular number >= M
    l = 1
    r = maxans
    lastgood = -1

    while l <= r:
     #   print("l is "+str(l))
    #    print("r is "+str(r))
        mid = (l+r)//2
        a = trng(mid)
        if a >= M:
            lastgood = mid
            r = mid-1
        else:
            l = mid+1
    
    print(lastgood+1)

#print(trng(4))