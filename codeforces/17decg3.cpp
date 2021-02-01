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

const int maxn = 100500;

int f[maxn], s[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> f[i] >> s[i];
    }

    multiset<int> S;

    int ans = 1e18;
    int idx = 1;
    int cur = f[1];
    S.emplace(s[1]);
    for(int i = 1; i <= n; i++) {
        while(idx < n and cur < m) {
            idx++;
            cur += f[idx];
            S.emplace(s[idx]);
        }
        if(cur >= m) {
            ans = min(ans, *S.rbegin());
        }

        cur -= f[i];
        S.erase(S.lower_bound(s[i]));
    }

    cout << ans << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
