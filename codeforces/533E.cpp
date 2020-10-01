// https://codeforces.com/contest/533/problem/E

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

    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;
    
    s = "."+s;
    t = "."+t;

    int l, r;

    for(int i = 1; i <= n; i++) {
        if(s[i] != t[i]) {
            l = i;
            break;
        }
    }

    for(int i = n; i >= 1; i--) {
        if(s[i] != t[i]) {
            r = i;
            break;
        }
    }

    int ans = 0;

    int len = r-l+1;

    if(s.substr(l+1, len-1) == t.substr(l, len-1)) ans++;
    if(s.substr(l, len-1) == t.substr(l+1, len-1)) ans++;

    cout << ans << endl;
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
