// https://codeforces.com/contest/1408/problem/D

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

const int maxn = 2050;
const int maxv = (int)1e6+500;
int a[maxn], b[maxn], c[maxn], d[maxn];

int sma[maxv];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> c[i] >> d[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] <= c[j]) {
                int x = c[j]-a[i];
                sma[x] = max(sma[x], d[j]-b[i]+1);
            }
        }
    }  

    int ma = 0;
    int ans = LLONG_MAX;

    for(int i = 1e6; i >= 0; i--) {
        ma = max(ma, sma[i]);
        ans = min(ans, i+ma);
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
