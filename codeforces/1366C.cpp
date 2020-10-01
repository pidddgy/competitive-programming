// https://codeforces.com/contest/1366/problem/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxnm = 35;

const vector<pii> dir = {{1, 0}, {0, 1}};
const vector<pii> rdir = {{-1, 0}, {0, -1}};

int a[maxnm][maxnm];

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

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }

        set<pii> S1 = {pii(1, 1)};
        set<pii> S2 = {pii(n, m)};

        int ans = 0;
        int totlen = n+m-2;

        // cout << totlen << endl;
        int skip = -1;

        if(totlen % 2 == 0) {
            skip = totlen/2+1;
        }
        for(int i = 1; i <= totlen; i++) {
            if(!(i==skip)) {
                int z = 0, o = 0;
        
                set<pii> all;
                for(pii x: S1) all.emplace(x);
                for(pii x: S2) all.emplace(x);

                for(pii x: all) {
                    if(a[x.fi][x.se]) o++;
                    else z++;
                }

                ans += min(z, o);

                if(z <= o) {
                    for(pii x: all) {
                        if(a[x.fi][x.se] == 0) a[x.fi][x.se] = 1;
                    }
                } else {
                    for(pii x: all) {
                        if(a[x.fi][x.se] == 1) a[x.fi][x.se] = 0;
                    }
                }
            }

            set<pii> S1n, S2n;
            for(pii x: S1) {
                for(pii d: dir) {
                    if(ok(x.fi+d.fi, x.se+d.se)) {
                        S1n.emplace(pii(x.fi+d.fi, x.se+d.se));
                    }
                }
            }

            for(pii x: S2) {
                for(pii d: rdir) {
                    if(ok(x.fi+d.fi, x.se+d.se)) {
                        S2n.emplace(pii(x.fi+d.fi, x.se+d.se));
                    }
                }
            }

            S1.clear(); S2.clear();
            S1 = S1n;
            S2 = S2n;
            cerr << endl;
        }

        cout << ans << endl;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                a[i][j] = 0;
            }
        }
    }
}
