// https://codeforces.com/contest/1365/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 55;

char a[maxn][maxn];
bool vis[maxn][maxn];
vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
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

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            a[i][j] = '?';
        }
    }

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m;

        for(int i = 1; i <= n; i++) {
            string row;
            cin >> row;

            for(int j = 0; j < m; j++) {
                a[i][j+1] = row[j];
            }
        }

        queue<int> rQ;
        queue<int> cQ;

        bool init = true;
        if(a[n-1][m] == 'B') init = false;
        if(a[n][m-1] == 'B') init = false;
        if(a[n-1][m-1] == 'B') init = false;

        if(init) {
            rQ.push(n);
            cQ.push(m);
            vis[n][m] = true;   
        }
        string ans = "Yes";


        while(!rQ.empty()) {
            int r = rQ.front(); rQ.pop();
            int c = cQ.front(); cQ.pop();

            for(pii d: dir) {
                if((!vis[r+d.fi][c+d.se]) and (a[r+d.fi][c+d.se] != '#') and (ok(r+d.fi, c+d.se))) {
                    bool good = true;
                    for(pii d2: dir) {
                        if(a[r+d.fi+d2.fi][c+d.se+d2.se] == 'B') {
                            good = false;
                        }
                    }

                    if(good) {
                        rQ.push(r+d.fi);
                        cQ.push(c+d.se);
                        vis[r+d.fi][c+d.se] = true;
                    }
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if((a[i][j] == 'G') and (!vis[i][j])) {
                    ans = "No";
                }
            }
        }

        cout << ans << endl;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                a[i][j] = '?';
                vis[i][j] = false;
            }
        }
    }
}
