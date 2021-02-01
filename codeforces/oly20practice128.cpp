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

int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t, m;
    cin >> n >> t >> m;

    for(int i = 1; i <= n; i++) {
        a[i] = t-m;
    }

    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;

        a[x]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > 0) ans++;
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
