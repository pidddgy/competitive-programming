// https://codeforces.com/contest/711/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define int long long
const int INF = 10000000500000;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    int c[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> c[i];
    }

    int cost[N+1][M+1];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> cost[i][j];
        }
    }

    int dp[N+1][K+1][M+1];

    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= K; j++) {
            for(int k = 0; k <= M; k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    if(c[1] == 0) {
        for(int i = 1; i <= M; i++) {
            dp[1][1][i] = cost[1][i];
        }
    } else {
        dp[1][1][c[1]] = 0;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            if(c[i] == 0) {
                for(int k = 1; k <= M; k++) {
                    dp[i][j][k] = dp[i-1][j][k]+cost[i][k];

                    for(int l = 1; l <= M; l++) {
                        if(l == k) continue;
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-1][l]+cost[i][k]);
                    }
                    cerr << i << "," << j << "," << k << " - " << dp[i][j][k] << endl;
                }
            } else {
                dp[i][j][c[i]] = dp[i-1][j][c[i]];
                for(int k = 1; k <= M; k++) {
                    if(k == c[i]) continue;
                    dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i-1][j-1][k]);
                }
                cerr << i << "," << j << "," << c[i] << " - " << dp[i][j][c[i]] << endl;
            }
        }
    }

    int ans = INF;
    for(int i = 1; i <= M; i++) {
        ans = min(ans, dp[N][K][i]);
    }

    if(ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }


}