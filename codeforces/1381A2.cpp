// https://codeforces.com/contest/1381/problem/A2

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
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    a = "."+a;
    b = "."+b;

    bool f = false;
    int l = 1;
    int r = n;

    // current segment that we didnt use + flipped or not
    vector<int> ans;
    for(int i = n; i >= 1; i--) {
        if(!f) {
            if(b[i] == a[l]) {
                ans.emplace_back(1);
            }
            ans.emplace_back(r-l+1);
            l++;
        } else {
            if(b[i] != a[r]) {
                ans.emplace_back(1);
            }
            ans.emplace_back(r-l+1);
            r--;
        }

        f ^= 1;
    }

    cout << sz(ans) << " ";
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
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
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
