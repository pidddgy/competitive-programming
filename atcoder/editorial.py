#!python3

N, S = map(int,input().split())
A = list(map(int,input().split()))
mod = 998244353
dp = [[0 for j in range(S + 1)] for i in range(N + 1)]
dp[0][0] = 1
for i in range(N) : 
    for j in range(S + 1) : 
        print("currently on "+str(i) + " " + str(j))
        dp[i + 1][j] += 2 * dp[i][j]
        dp[i + 1][j] %= mod 
        if j + A[i] <= S : 
            dp[i + 1][j + A[i]] += dp[i][j]
            dp[i + 1][j + A[i]] %= mod
for i in range(N + 1) : 
    for j in range(S + 1) : 
        print(dp[i][j], end = " ")
    print()
print(dp[N][S])