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


int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

void solve() {
    string s, t;
    cin >> s >> t;

    if(sz(s) > sz(t)) swap(s, t);

    int l = lcm(sz(s), sz(t));
    string ans = "";

    for(int i = 1; i <= l/sz(s); i++) {
        ans += s;
    }

    string other = "";
    for(int i = 1; i <= l/sz(t); i++) {
        other += t;
    }

    if(ans == other) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
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

take the shorter string and make a bunch of copies
max size is like 17*19 or something

2000 * 2000 = 4 000 000

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
