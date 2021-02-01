// https://dmoj.ca/problem/ccc04s1

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

string a[5];

bool cmp(string l, string r) {
    return sz(l) < sz(r);
}

void solve() {
    for(int i = 1; i <= 3; i++) {
        cin >> a[i];
    }
    sort(a+1, a+3+1, cmp);

    string ans = "Yes";
    for(int i = 1; i <= 3; i++) {
        for(int j = i+1; j <= 3; j++) {
            if(a[i] == a[j].substr(0, sz(a[i]))) ans = "No";
            if(a[i] == a[j].substr(sz(a[j])-sz(a[i]), sz(a[i]))) ans = "No";
        }
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

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
