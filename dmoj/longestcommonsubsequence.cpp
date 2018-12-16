// https://dmoj.ca/problem/lcs

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
using namespace std;

int main() {
    int N, M;
    scanf("%i%i", &N, &M);
    
    int dp[N+1][M+1];
    int seqN[N];
    int seqM[M];

    for(int i = 0; i < N; i++)
        scanf("%i", &seqN[i]);
    for(int i = 0; i < M; i++)
        scanf("%i", &seqM[i]);
    
    for(int i = 0; i < N+1; i++)
        dp[i][0] = 0;
    for(int i = 0; i < M+1; i++)
        dp[0][i] = 0;

    for(int i = 1; i < N+1; i++)
        for(int j = 1; j < M+1; j++)
            if(seqN[i-1] == seqM[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    
    printf("%i\n", dp[N][M]);
}
