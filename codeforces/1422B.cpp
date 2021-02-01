// https://codeforces.com/contest/1422/problem/B

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

const int maxn = 105;

int a[maxn][maxn];
void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    set<set<pii>> S;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            set<pii> T;
 
            T.emplace(i, j);
            T.emplace(n-1-i, j);

            T.emplace(i, m-1-j);
            T.emplace(n-1-i, m-1-j);
 
            S.emplace(T);
        }
    }

    int ans = 0;
    for(auto x: S) {
        for(pii y: x) {
            cerr << y.fi << " " << y.se << endl;
        }

        int mi = LLONG_MAX;
        for(pii y: x) {
            cerr << "trying " << a[y.fi][y.se] << endl;
            int loc = 0;
            for(pii z: x) {
                cerr << z.fi << " " << z.se << " adds " << abs(a[z.fi][z.se]-a[y.fi][y.se]) << endl;
                watch(a[z.fi][z.se])
                loc += abs(a[z.fi][z.se]-a[y.fi][y.se]);
            }
            watch(loc)

            mi = min(mi, loc);
        }

        watch(mi)
        cerr << endl;


        ans += mi;
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

get all 4 indexes and push into set, number of distinct values minus the biggest one

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
