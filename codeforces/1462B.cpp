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
string s;

string get(int l, int r) {
    return s.substr(l, r-l+1);
}
void solve() {
    int n;
    cin >> n;

    cin >> s;

    s = "."+s;

    bool ok = false;
    if(get(n-3, n) == "2020") ok = true;
    if(get(1, 1) == "2" and get(n-2, n) == "020") ok = true;
    if(get(1, 2) == "20" and get(n-1, n) == "20") ok = true;
    if(get(1, 3) == "202" and get(n, n) == "0") ok = true;
    if(get(1, 4) == "2020") ok = true;

    if(ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
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
