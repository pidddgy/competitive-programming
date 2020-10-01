// https://codeforces.com/contest/1375/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;

bool ok(int x, int y) {
    if(1 <= x and x <= n) {
        if(1 <= y and y <= m) {
            return true;
        }
    }
    return false;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m;

        int ans[n+1][m+1];

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int cnt = 0;
                for(pii d: dir) {
                    if(ok(i+d.fi, j+d.se)) {
                        cnt++;
                    }
                }

                ans[i][j] = cnt;
            }
        }

        bool ok = true;
        int a[n+1][m+1];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> a[i][j];

                if(a[i][j] > ans[i][j]) ok = false;
            }
        }

        if(ok) {
            cout << "YES" << endl;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            cout << "NO" << endl;
        }

    }
}
