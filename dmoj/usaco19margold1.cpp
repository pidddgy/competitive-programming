// https://dmoj.ca/problem/usaco19margold1

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int maxn = 405;

int a[maxn];
int dp[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            dp[i][j] = INT_MAX;
        }
    }

    dp[0][0] = 0;

    int N, K;
    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K+1; j++) {
            int ma = 0;
            int sum = 0;
            int mi = INT_MAX;

            // combine elements
            for(int k = i; k >= 1; k--) {
                ma = max(ma, a[k]);
                sum += a[k];
                
                int inc = (ma*(i-k+1))-sum;
                mi = min(mi, inc+dp[k-1][j-1]);
            }

            dp[i][j] = min(dp[i][j], mi);
        }
    }

    cout << dp[N][K+1] << endl;
}
