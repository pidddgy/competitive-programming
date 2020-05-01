// https://codeforces.com/contest/616/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1005;
int n, m;

char a[maxn][maxn];
pii par[maxn][maxn];
int sz[maxn][maxn];

pii findp(pii x) {
    if(par[x.fi][x.se] == x) {
        return x;
    } else {
        return par[x.fi][x.se] = findp(pii(par[x.fi][x.se].fi, par[x.fi][x.se].se));
    }
}

void merge(pii x, pii y) {
    pii xp = findp(x);
    pii yp = findp(y);

    if(xp == yp) return;

    par[xp.fi][xp.se] = pii(yp.fi, yp.se);
    sz[yp.fi][yp.se] += sz[xp.fi][xp.se];
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            par[i][j] = pii(i, j);
            sz[i][j] = 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == '*') {
                sz[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == '.') {
                if(i+1 <= n) {
                    if(a[i+1][j] == '.') {
                        merge(pii(i, j), pii(i+1, j));
                    }
                }
                
                if(j+1 <= m) {
                    if(a[i][j+1] == '.') {
                        merge(pii(i, j), pii(i, j+1));
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // cerr << "on " << i << "," << j << endl;
            if(a[i][j] == '*') {
                pii l = findp(pii(i, j-1));
                pii r = findp(pii(i, j+1));
                pii u = findp(pii(i-1, j));
                pii d = findp(pii(i+1, j));

                set<pii> adjs;
                if(j-1 >= 1) adjs.emplace(l);
                if(j+1 <= m) adjs.emplace(r);
                if(i-1 >= 1) adjs.emplace(u);
                if(i+1 <= n) adjs.emplace(d);

                int ans = 0;
                for(pii adj: adjs) {
                    ans += sz[adj.fi][adj.se];
                    // watch(sz[adj.fi][adj.se])
                }

                cout << (ans+1)%10;
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}