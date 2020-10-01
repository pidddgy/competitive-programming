#!python3

MAXN = 1500
MOD = 1000000007

n = int(input())
dp = [0]*MAXN

p = list(map(int, input().split()))

for i in range(n):
    s1 = dp[i];
    s2 = 2;
    s3 = dp[i]-dp[p[i]-1];

    dp[i+1] = s1 + s2 + s3;
    dp[i+1] %= MOD

print(dp[n])

