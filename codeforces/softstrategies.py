

def totient(n) :          # n - unsigned int
    result = 1
    p = 2                 #prime numbers - 'iterator'
    while p**2 <= n :
        if(n%p == 0) :    # * (p-1)
            result *= (p-1)
            n /= p
        while(n%p == 0) : # * p^(k-1)
            result *=  p
            n /= p
        p += 1
    if n != 1 :
        result *= (n-1)
    return result
 
def modpow(p, z, b, c, m) : # (p^z)^(b^c) mod m
    if m == 2:
        return p % m
    cp = 0
    while m % p == 0 :
        cp += 1
        m /= p              # m = m' now
    t = totient(m)
    exponent = ((pow(b,c,t)*z)%t + t - (cp%t))%t
                            # exponent = z*(b^c)-cp mod t
    return pow(p, cp)*pow(p, exponent, m)
 
def solve(a,b,c,m) : #split
    result = 1
    p = 2
    while p**2 <= a :
        cp = 0
        while a%p == 0 :
            a /= p
            cp += 1
        if cp != 0 :
           temp =  modpow(p,cp,b,c,m)
           result *= temp
           result %= m
        p += 1
    if a != 1 :
        result *= modpow(a, 1, b, c, m)
    return result % m

# print(solve(3, 5, 7, 17))

def f(x,e,m):
    X = x
    E = e
    Y = 1
    while E > 0:
        if E % 2 == 0:
            X = (X * X) % m
            E = E/2
        else:
            Y = (X * Y) % m
            E = E - 1
    return Y




n, m = map(int, input().split())

a = [int(x) for x in input().split()]

if n == 1:
    print(a[0])
elif n == 2:
    print(f(a[0], a[1], m))
elif n == 3:
    print(solve(a[0], a[1], a[2], m))
