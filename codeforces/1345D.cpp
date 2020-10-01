// https://codeforces.com/contest/1345/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1005;

char a[maxn][maxn];
bool vis[maxn][maxn];

vector<pii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            a[i][j] = '?';
        }
    }

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= m; j++) {
            a[i][j] = s[j-1];
        }
    }

    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == '#' and a[i][j-1] != '#') cnt++;
        }

        if(cnt > 1) {
            cerr << "dsf" << endl;
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i = 1; i <= m; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(a[j][i] == '#' and a[j-1][i] != '#') cnt++;
        }

        if(cnt > 1) {
            cerr << "dsf" << endl;
            cout << -1 << endl;
            return 0;
        }
    }

    map<int, int> visR;
    map<int, int> visC;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cerr << i << "," << j << endl;
            watch(vis[i][j])
            if(a[i][j] == '#' and !vis[i][j]) {
                cerr << "on " << i << "," << j << endl;
                queue<int> rQ;
                queue<int> cQ;

                rQ.push(i);
                cQ.push(j);

               

                vis[i][j] = true;

                while(!rQ.empty()) {
                    int r = rQ.front(); rQ.pop();
                    int c = cQ.front(); cQ.pop();

                    visR[r] = true;
                    visC[c] = true;

                    for(pii x: dir) {
                        if((!vis[r+x.fi][c+x.se]) and a[r+x.fi][c+x.se] == '#') {
                            if(1 <= r+x.fi and r+x.fi <= n) {
                                if(1 <= c+x.se and c+x.se <= m) {
                                    rQ.push(r+x.fi);
                                    cQ.push(c+x.se);

                                    cerr << "marking " << r+x.fi << "," << c+x.se << endl;
                                    vis[r+x.fi][c+x.se] = true;
                                }
                            }
                        }
                    }
                }

                ans++;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            bool valid = true;
            for(int k = 1; k <= m; k++) {
                if(a[i][k] == '#') {
                    valid = false;
                }
            }

            for(int k = 1; k <= n; k++) {
                if(a[k][j] == '#') {
                    valid = false;
                }
            }

            if(valid) {
                visR[i] = true;
                visC[j] = true;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!visR[i]) {
            cerr << "failed on row " << i << endl;
            ans = -1;
        }
    }

    for(int i = 1; i <= m; i++) {
        if(!visC[i]) {
            cerr << "failed on col " << i << endl;
            ans = -1;
        }
    }

    cout << ans << endl;
}