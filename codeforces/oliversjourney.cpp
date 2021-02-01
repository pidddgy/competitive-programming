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

const int maxn = (int)2e6;
const int MOD = (int)1e9+7;

int n;
int a[maxn];
int d[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l,r;
    cin >> l >> r;
    d[0] = 1;

    set<pii> S;
    for(int i = 0; i <= n; i++) {
        if(sz(S)) {
        // cerr << (*S.begin()).fi << endl;
        // watch(a[i])
        }

        while(sz(S) and (*S.begin()).fi <= a[i]) {
            pii p = *S.begin();
            // cerr << "adding " << p.fi << " " << p.se << endl;
            d[i] += (*S.begin()).se;
            S.erase(S.begin());
        }

        S.emplace(a[i]+l, d[i]);
        S.emplace(a[i]+r+1, -d[i]);
        // cerr << "s begin is now " << (*S.begin()).fi << endl;
        // cerr << "pushing " << a[i]+l << " " << d[i] << endl;
        // cerr << "pushing " << a[i]+r+1 << " " << -d[i] << endl;
        
        // cerr << d[i] << endl;
        // cerr << endl;
    }
    for(int i = 0; i <= n; i++) {
        cerr << d[i] << " ";
    }
    cerr << endl;

    cout << d[n] << endl;
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
