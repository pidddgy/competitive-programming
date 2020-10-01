// https://codeforces.com/contest/444/problem/A

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 505;

int x[maxn];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    ld ans = 0;
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ld loc = ((ld)x[a]+x[b])/(ld)c;

        ans = max(ans, loc);
    }

    cout << ans << endl;
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
