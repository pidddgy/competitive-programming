#!python3
 
MOD = (10**9) + 7
n = int(input())
 
a = list(map(int, input().split()))
 
a = sorted(a)
ans = 0
for i in range(n):
    r = (2**i)-1
    r %= MOD
 
    ans += (r*a[i]) % MOD
    ans %= MOD
 
a.reverse()
 
for i in range(n):
    r = (2**i)-1
    r %= MOD
 
    ans -= ((r*a[i]) % MOD)
    ans %= MOD
 
print(ans)