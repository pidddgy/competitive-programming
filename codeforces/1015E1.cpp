// https://codeforces.com/contest/1015/problem/E1

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 105;

bool filled[maxn][maxn];
string a[maxn];
int n, m;

struct star {
    int x, y, sz;

    star(int xx, int yy, int szz) {
        x = xx;
        y = yy;
        sz = szz;
    }
};

vector<star> ans;

bool valid(pii x) {
    if ((1 <= x.fi) and (x.fi <= n) and (1 <= x.se) and (x.se <= m)) {
        return a[x.fi][x.se] == '*';
    } else return false;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        s = "."+s;

        a[i] = s;
        // for(int j = 1; j <= m; j++) {
        //     cin >> a[i][j];
        // }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] != '*') continue;
            pii l = pii(i, j), r = pii(i, j), u = pii(i, j), d = pii(i, j);
            int val = -1;
            for(int k = 1; k <= 2000; k++) {
                l.se--;
                r.se++;
                u.fi--;
                d.fi++;

                if(valid(l) and valid(r) and valid(u) and valid(d)) {
                    val = k;
                } else break;
            }

            if(val != -1) {
                l = pii(i, j), r = pii(i, j), u = pii(i, j), d = pii(i, j);
                filled[i][j] = true;
                for(int k = 1; k <= val; k++) {
                    l.se--;
                    r.se++;
                    u.fi--;
                    d.fi++;

                    for(pii x: set<pii>({l, r, u, d})) {
                        filled[x.fi][x.se] = true;
                    }
                }

                ans.emplace_back(star(i, j, val));
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == '*' and !filled[i][j]) {
                // assert(false);
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << ans.size() << endl;
    for(star s: ans) {
        cout << s.x << " " << s.y << " " << s.sz << endl;
    }
}
