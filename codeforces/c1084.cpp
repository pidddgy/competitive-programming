// https://cses.fi/problemset/task/1084

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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(all(a));
    sort(all(b));

    int ans = 0;

    while(sz(a) and sz(b)) {
        while(sz(a) and sz(b) and abs(a.back()-b.back()) > k) {
            if(a.back() > b.back()) a.pop_back();
            else b.pop_back();
        }

        if(a.empty() or b.empty()) break;

        ans++;
        a.pop_back();
        b.pop_back();
    }

    cout << ans << endl;
}

/*

repeatedly give biggest apartment to biggest person

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
