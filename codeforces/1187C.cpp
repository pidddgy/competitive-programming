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

void solve() {
    
}

const int maxn = 1005;

int n, m;
int a[maxn];
int d[maxn];
int t[maxn];
pii q[maxn];

bool sorted(int l, int r) {
    for(int i = l+1; i <= r; i++) {
        if(a[i] < a[i-1]) return false;
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> t[i] >> q[i].fi >> q[i].se;

        if(t[i] == 1) {
            d[q[i].fi+1]++;
            d[q[i].se+1]--;
        }
    }

    for(int i = 1; i <= n; i++) {
        a[i] = 1e9;
        d[i] += d[i-1];
        if(!d[i] and i > 1) a[i] = a[i-1] - 1;
        cerr << d[i] << " ";
    }
    cerr << endl;

    string ans = "YES";
    for(int i = 1; i <= m; i++) {
        if(t[i] == 1) {
            if(!sorted(q[i].fi, q[i].se)) ans = "NO";
        } else {
            if(sorted(q[i].fi, q[i].se)) ans = "NO";
        }
    }

    cout << ans << endl;

    if(ans != "NO")
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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
