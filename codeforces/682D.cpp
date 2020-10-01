// https://codeforces.com/contest/682/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 1005;
const int maxk = 15;
// 1 = ending of a substring, 0 = not
int dp[maxn][maxn][maxk][2];
int N, M, K;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    string s, t;
    cin >> s >> t;

    s = "."+s;
    t = "."+t;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            for(int k = 1; k <= K; k++) {
                dp[i][j][k][0] = max(dp[i-1][j][k][0], dp[i][j-1][k][0]);

                if(s[i] == t[j]) {
                    dp[i][j][k][1] = max(dp[i-1][j-1][k][1], dp[i-1][j-1][k-1][0]) + 1;
                }

                dp[i][j][k][0] = max(dp[i][j][k][0], dp[i][j][k][1]);
            }
        }
    }

    cout << dp[N][M][K][0] << endl;
}