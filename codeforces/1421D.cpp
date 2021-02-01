// https://codeforces.com/contest/1421/problem/D

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

vector<int> dx = {-1, 1, 0, -1, -1, 0, 1};
vector<int> dy = {-1, 1, 1, 0, -1, -1, 0};

map<int, map<int, int>> c;

int x, y;
int ans = 0;

void go() {
    if(x == 0 and y == 0) return;

    int cx = 0, cy = 0;
    if(x < 0) cx = -1;
    else if(x > 0) cx = 1;

    if(y < 0) cy = -1;
    else if(y > 0) cy = 1;
    
    if(cx == 0 and cy == 0) return;
    watch(x)
    watch(y)
    cerr << cx << " " << cy << endl;
    watch(c[cx][cy])

    int take = LLONG_MAX;
    if(cx) {
        take = min(take, x/cx);
    }

    if(cy) {
        take = min(take, y/cy);
    }
    // int take = min(x/max(1LL, cx), y/max(1LL, cy));
    watch(take)

    x -= take*cx;
    y -= take*cy;


    assert(c[cx][cy] < 1e18);
    ans += c[cx][cy]*take;
    cerr << endl;
}

void solve() {
    ans = 0;
    for(int i = -15; i < 15; i++) {
        for(int j = -15; j < 15; j++) {
            c[i][j] = LLONG_MAX;
        }
    }
    c[0][0] = 0;

    cin >> x >> y;

    for(int i = 1; i <= 6; i++) {
        int _;
        cin >> _;

        c[dx[i]][dy[i]] = _;
    }

    for(int i = 0; i <= 6; i++) {
        for(int j = 0; j <= 6; j++) {
            pii to = {0, 0};
            int sum = 0;
            for(int x: vector<int>({i, j})) {
                if(x == 0) continue;

                to.fi += dx[x];
                to.se += dy[x];
                sum += c[dx[x]][dy[x]];
            }

            c[to.fi][to.se] = min(c[to.fi][to.se], sum);
        }
    }

    for(int i = 1; i <= 4; i++) {
        go();
    }


    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

pairs are

sideways
0, 1
-1, 0

up
1, 0
1, 1

down
-1. -1
-1, 0

combine at most 4

1, 0
-1, 1
-1, -1


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
