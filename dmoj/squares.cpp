// https://dmoj.ca/problem/dmopc19c2p2

#include <bits/stdc++.h>
using namespace std;

long long a[600][600];
long long dp[600][600];
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
#define int long long
    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i <= N; i++)
    for(int j = 0; j <= M; j++)
        dp[i][j] = 2147483647;
    
    dp[1][1] = a[1][1];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(i == 1 and j == 1) continue;
            dp[i][j] = a[i][j] + min(dp[i-1][j], dp[i][j-1]);
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    cout << dp[N][M] << endl;
    




}