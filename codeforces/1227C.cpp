// https://codeforces.com/contest/1227/problem/C

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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    s = "."+s;

    string t = ".";
    for(int i = 1; i <= k-1; i++) {
        t += "()";
    }

    for(int i = 1; i <= n/2-(k-1); i++) {
        t += '(';
    }
    for(int i = 1; i <= n/2-(k-1); i++) {
        t += ')';
    }

    vector<pii> ans;
    for(int i = 1; i <= n; i++) {
        if(s[i] == t[i]) continue;

        for(int j = i+1; j <= n; j++) {
            if(s[j] == t[i]) {
                int len = j-i+1;

                string flip = s.substr(i, len);
                reverse(all(flip));

                for(int k = 0; k < sz(flip); k++) {
                    s[i+k] = flip[k];
                }

                ans.emplace_back(i, j);

                break;
            }
        }
    }

    cout << sz(ans) << endl;
    for(pii x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
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
