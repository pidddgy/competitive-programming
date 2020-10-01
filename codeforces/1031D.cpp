// https://codeforces.com/contest/1031/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 2500;

int n, k;
char a[maxn][maxn];
int dp[maxn][maxn];

bool ok(int x, int y) {
    return (x <= n and y <= n);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < n; j++) {
            a[i][j+1] = s[j];
        }
    }

    dp[1][1] = 0;

    int ma = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = min({dp[i][j], dp[i-1][j], dp[i][j-1]});
            if(a[i][j] != 'a') {
                dp[i][j]++;
            }

            if(dp[i][j] <= k) {
                ma = max(ma, i+j-2);
            }
        }
    }

    set<pii> S;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i+j-2 == ma and dp[i][j] <= k) {
                S.emplace(i, j);
            }
        }
    }

    string ans;

    if(S.empty()) {
        ans += a[1][1];
        S.emplace(1, 1);
    }

    for(int i = 1; i <= 2*n-1-ma; i++) {
        if(S.count({n, n})) break;

        set<pii> ne;

        char mi = 'z';
        for(pii x: S) {
            if(ok(x.fi+1, x.se)) {
                mi = min(mi, a[x.fi+1][x.se]);
            }

            if(ok(x.fi, x.se+1)) {
                mi = min(mi, a[x.fi][x.se+1]);
            }
        }

        for(pii x: S) {
            if(ok(x.fi+1, x.se)) {
                if(a[x.fi+1][x.se] == mi) {
                    ne.emplace(x.fi+1, x.se);
                }
            }

            if(ok(x.fi, x.se+1)) {
                if(a[x.fi][x.se+1] == mi) {
                    ne.emplace(x.fi, x.se+1);
                }
            }
        }

        S = ne;
        ans += mi;
    }

    while(ans.size() < 2*n-1) {
        ans = "a"+ans;
    }

    cout << ans << endl;
}
