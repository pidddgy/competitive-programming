// https://codeforces.com/problemset/problem/627/A

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

void no() {
    cout << 0 << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int s, x;
    cin >> s >> x;

    int a = (s-x);
    if(a&1) no();
    a /= 2;

    int ans = 1;
    for(int i = 0; i <= 55; i++) {
        if(x & (1LL << i)) {
            if(a & (1LL << i)) no();

            ans *= 2;
        }
    }

    // the only case where a or b can be 0 is if s == x
    if(s == x) ans -= 2;

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
