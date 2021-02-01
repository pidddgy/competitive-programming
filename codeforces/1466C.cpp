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

int n;

void solve() {
    string s;
    cin >> s;
    n = sz(s);
    s = "."+s;
    
    vector<int> v;
    for(int i = 1; i <= n-1; i++) {
        if(s[i] == s[i+1]) {
            v.emplace_back(i+1);
        }
    }

    for(int i = 1; i <= n-2; i++) {
        if(s[i] == s[i+2]) {
            v.emplace_back(i+2);
        }
    }

    sort(all(v));

    int ans = 0;
    for(int i: v) {
        if(s[i] == s[i-1] and s[i] != '?') {
            s[i] = '?';
            ans++;
        } else if(i >= 3 and s[i] == s[i-2] and s[i] != '?') {
            s[i] = '?';
            ans++;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

observation: only fix substrings of size 2 or 3

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
