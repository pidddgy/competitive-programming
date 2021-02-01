// https://codeforces.com/contest/1440/problem/C1

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


int dis[50];
int par[50];

const int maxn = 105;
int n,m;

int a[maxn][maxn];

void solve() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= m; j++) {
            a[i][j] = s[j-1]-'0';
        }
    }

    vector<vector<pii>> ans;
    // do all the middle squares, just do whatever and force everything to edges
    for(int i = 1; i <= n-2; i++) {
        for(int j = 1; j <= m-2; j++) {
            if(a[i][j] == 0) continue;

            vector<pii> cur;
            cerr << "on " << i << " " << j << endl;

            a[i][j] ^= 1;
            a[i][j+1] ^= 1;
            a[i+1][j] ^= 1;

            cur.emplace_back(i, j);
            cur.emplace_back(i, j+1);
            cur.emplace_back(i+1, j);

            ans.emplace_back(cur);

            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    cerr << a[i][j] << " ";
                }
                cerr << endl;
            }
        }
    }

    // push right edge down
    for(int i = 1; i <= n-2; i++) {
        if(a[i][m-1]+a[i][m] == 0) continue;
        
        vector<pii> cur;
        for(int j = 1; j <= )
        int rem = 3;
        if(a[i][m-1]) {
            a[i][m-1] = 0;
            cur.emplace_back(i, m-1);
            rem--;
        }

        if(a[i][m]) {
            a[i][m] = 0;
            cur.emplace_back(i, m);
            rem--;
        }

        if(rem) {
            cur.emplace_back(i+1, m-1);
            a[i+1][m-1] ^= 1;
            rem--;
        }

        if(rem) {
            cur.emplace_back(i+1, m);
            a[i+1][m] ^= 1;
            rem--;
        }

        ans.emplace_back(cur);
    }

    // push bottom edge to the right
    for(int j = 1; j <= m-2; j++) {
        if(a[n-1][j] + a[n][j] == 0) continue;

        vector<pii> cur;
        int rem = 3;

        if(a[n-1][j]) {
            a[n-1][j] = 0;
            cur.emplace_back(n-1, j);
            rem--;
        }

        if(a[n][j]) {
            a[n][j] = 0;
            cur.emplace_back(n, j);
            rem--;
        }

        if(rem) {
            cur.emplace_back(n-1, j+1);
            a[n-1][j+1] ^= 1;
            rem--;
        }

        if(rem) {
            cur.emplace_back(n, j+1);
            a[n][j+1] ^= 1;
            rem--;
        }

        ans.emplace_back(cur);
    }

    while(a[n-1][m-1]+a[n-1][m]+a[n][m-1]+a[n][m] != 0) {
        vector<pii> v = {{n-1, m-1}, {n-1, m}, {n, m-1}, {n, m}};
        int mask = 0;

        for(int i = 0; i < 4; i++) {
            pii p = v[i];
            if(a[p.fi][p.se]) {
                mask ^= (1 << i);
            }
        }

        int op = par[mask];

        vector<pii> cur;
        for(int i = 0; i < 4; i++) {
            pii p = v[i];
            if(op & (1 << i)) {
                a[p.fi][p.se] ^= 1;
                cur.emplace_back(p.fi, p.se);
            }
        }

        assert(sz(cur) == 3);

        ans.emplace_back(cur);
    }
    

    cout << sz(ans) << endl;
    for(auto x: ans) {
        for(pii y: x) {
            cout << y.fi << " " << y.se << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 50; i++) dis[i] = INT_MAX;
    // bitmask
    queue<int> Q;
    Q.push(0);
    dis[0] = 0;

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();

        for(int i = 0; i <= 15; i++) {
            int bits = 0;
            vector<int> v;
            for(int j = 0; j < 4; j++) {
                if((1<<j) & i) {
                    bits++;
                    v.emplace_back((1<<j));
                }
            }

            if(bits == 3) {
                int to = S;
                for(int x: v) {
                    to ^= x;
                }

                if(dis[to] > dis[S]+1) {
                    Q.push(to);
                    dis[to] = dis[S]+1;
                    par[to] = i;
                }
            }
        }   
    }

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

push to bottom and right
brute force the last one

always under n+m because we don't do the edge pieces

if it is on the right edge then push down
if on bottom edge push to right
otherwise do whatever

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
