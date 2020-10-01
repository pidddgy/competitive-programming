// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff48/00000000003f4ed8

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

const int maxn = 100500;

int a[maxn];
void solve() {
    int n, x;
    cin >> n >> x;

    vector<pii> v;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        v.emplace_back((a[i]+(x-1))/x, i);
    }

    sort(all(v));

    for(pii p: v) {
        cout << p.se << " ";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++) {
        cout << "Case #"<<tc << ": ";
        solve();
        cout << endl;
    }
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
