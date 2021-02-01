// https://dmoj.ca/problem/oly20practice123

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int unsigned long long
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
    cin >> n;
    string s = to_string(n);
    int ans = 0;
    int cur = 9;
    int l = 1;
    for(int i = 1; i <= sz(s); i += 2) {
        ans += min(cur, n)-l+1;

        cerr << min(cur,n) << " - " << l << endl;

        cur *= 10;
        cur += 9;
        cur *= 10;
        cur += 9;

        l *= 100;
    }

    cout << ans << endl;
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
