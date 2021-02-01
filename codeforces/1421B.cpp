// https://codeforces.com/contest/1421/problem/B

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

int n;
char a[300][300];
bool vis[300][300];

const vector<pii> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void cl() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            vis[i][j] = false;
        }
    }
}

bool inside(int r, int c) {
    if(1 <= r and r <= n) {
        if(1 <= c and c <= n) {
            return true;
        }
    }

    return false;
}

bool go(int dig) {
    cl();
    queue<int> rQ, cQ;
    rQ.push(1);
    cQ.push(1);
    vis[1][1] = true;

    while(sz(rQ)) {
        int r = rQ.front(); rQ.pop();
        int c = cQ.front(); cQ.pop();

        for(pii d: dir) {
            if(inside(r+d.fi, c+d.se) and !vis[r+d.fi][c+d.se]) {
                if((a[r+d.fi][c+d.se]-'0' == dig) or (r+d.fi == n and c+d.se == n)) {
                    rQ.push(r+d.fi);
                    cQ.push(c+d.se);
                    vis[r+d.fi][c+d.se] = true;
                }
            }
        }
    }

    return vis[n][n];
}

void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    vector<pii> squares = {{1, 2}, {2, 1}, {n-1, n}, {n, n-1}};
    for(int mask = 0; mask < (1<<4); mask++) {
        watch(mask)
        int cnt = 0;
        for(int i = 0; i < 4; i++) {
            if((1<<i) & mask) {
                if(a[squares[i].fi][squares[i].se] == '0') {
                    a[squares[i].fi][squares[i].se] = '1';
                } else {
                    a[squares[i].fi][squares[i].se] = '0';
                }
                cnt++;
            }
        }

        if(!(go(0) or go(1)) and cnt <= 2) {
            cerr << "using mask " << mask << endl;
            // for(int ii = 1; ii <= n; ii++) {
            //     for(int jj = 1; jj <= n; jj++) {
            //         cerr << a[ii][jj];
            //     }
            //     cerr << endl;
            // }
            cout << cnt << endl;
            for(int i = 0; i < 4; i++) {
                if((1<<i) & mask) {
                    cout << squares[i].fi << " " << squares[i].se << endl;
                }
            }
            return;
        }

        // flip back after
        for(int i = 0; i < 4; i++) {
            if((1<<i) & mask) {
                if(a[squares[i].fi][squares[i].se] == '0') {
                    a[squares[i].fi][squares[i].se] = '1';
                } else {
                    a[squares[i].fi][squares[i].se] = '0';
                }
            
            }
        }
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
