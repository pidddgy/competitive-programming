// https://codeforces.com/contest/841/problem/C

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

const int maxn = 200500;

int a[maxn], b[maxn];
int ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<pii> v;
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        v.emplace_back(b[i], i);
    }

    sort(all(v));

    for(pii x: v) {
        cerr << x.fi << " " << x.se << endl;
    }

    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);

    for(int i = 1; i <= n; i++) {
        ans[v[i-1].se] = a[i];
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
