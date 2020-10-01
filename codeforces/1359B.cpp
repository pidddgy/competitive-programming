// https://codeforces.com/contest/1359/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second
int n, m, x, y;

bool ok(int r, int c) {
    if(1 <= r and r <= n) {
        if(1 <= c and c <= m) {
            return true;
        }
    }

    return false;
}

const vector<pii> dir = {{0, 1}, {0, -1}};

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m >> x >> y;

        char a[n+1][m+1];
        int cntw = 0;
        for(int i = 1; i <= n; i++) {
            string s;
            cin >> s;

            s = "."+s;
            for(int j = 1; j <= m; j++) {
                a[i][j] = s[j];
                cntw += s[j]=='.';
            }
        }

        if(y >= x*2) {
            cout << cntw*x << endl;
            continue;
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(pii x: dir) {
                    if(ok(i+x.fi, j+x.se)) {
                        if(a[i+x.fi][j+x.se]=='.' and a[i][j]=='.') {
                            ans += y;
                            a[i][j] = '*';
                            a[i+x.fi][j+x.se] = '*';
                        }
                    }
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                ans += (a[i][j]=='.')*x;
            }
        }

        cout << ans << endl;
    }
}
