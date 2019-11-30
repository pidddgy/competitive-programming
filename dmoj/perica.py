#!python3

N, K = map(int, input().split())

MAXN = 100005
MOD = 1000000007 

fact = [0] * MAXN
for i in range(2, MAXN):
    fact[i] = fact[i-1] * i

def choose(n, k):
    if(k > n):
        return 0
    return (fact[n] / (fact[k] * fact[n-k])) % MOD


a = [int(x) for x in input().split()]

cnt = {}

for x in a: cnt[x] += 1
