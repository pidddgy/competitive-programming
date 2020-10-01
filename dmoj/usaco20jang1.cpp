// https://dmoj.ca/problem/usaco20jang1

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

// It's never worth it to go for more than 1000 days
const int maxn = 1005, maxd = 1005;

int N, M, C;
int dp[maxd][maxn];
int m[maxn];

// G -> edges, P -> edges in reverse
vector<int> G[maxn];

int sq(int n) {
    return n*n;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxd; i++) {
        for(int j = 0; j < maxn; j++) {
            dp[i][j] = INT_MIN;
        }
    }

    cin >> N >> M >> C;

    for(int i = 1; i <= N; i++) {
        cin >> m[i];
    }

    for(int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;

        G[b].emplace_back(a);
    }

    dp[1][1] = 0;

    for(int i = 2; i < maxd; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k: G[j]) {
                dp[i][j] = max(dp[i][j], dp[i-1][k]+m[j]);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i < maxd; i++) {
        ans = max(ans, dp[i][1] - C*sq(i-1));
    }

    cout << ans << endl;
}
