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

    for(int i = 1; i <= n-1; i++) {
        for(int j = 1; j <= m-1; j++) {
            vector<pii> v = {{i, j}, {i, j+1}, {i+1, j}, {i+1, j+1}};

            int sum = 0;

            if(i == n-1 and a[n][j] == 1) {

            } else if(j == m-1 and a[i][m] == 1) {

            } else if(i == n-1 and j == m-1 and a[n][m] == 1) {

            } else {
                if(a[i][j] == 0) continue;
            }

            while(a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1] != 0) {
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
        }
    }

    assert(sz(ans) <= 3*n*m);
    cout << sz(ans) << endl;
    for(auto x: ans) {
        for(pii y: x) {
            cout << y.fi << " " << y.se << " ";
        }
        cout << endl;
    }
    

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cerr << a[i][j] << " ";
            // assert(a[i][j] == 0);
        }
        cerr << endl;
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

        // cerr << "on " << S << endl;
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
                // watch(i)
                int to = S;
                for(int x: v) {
                    // cerr << "xor with " << x << endl;
                    to ^= x;
                }
                // watch(to)

                if(dis[to] > dis[S]+1) {
                    Q.push(to);
                    dis[to] = dis[S]+1;
                    par[to] = i;
                }
            }
        }   
        cerr << endl;
    }

    // watch(dis[7])
    // watch(par[7])
    // watch(dis[5])
    // watch(par[5])
    // watch(dis[15])
    // am convinced this works, pray

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

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
