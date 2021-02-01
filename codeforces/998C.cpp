// https://codeforces.com/contest/998/problem/C

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
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;

    string s;
    cin >> s;

    s = "."+s;

    int runs = 0, len = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '0') {
            len++;
        } else {
            if(len) {
                runs++;
                len = 0;
            }
        }
    }

    if(len) runs++;

    int ans = LLONG_MAX;
    if(runs == 0) ans = 0;
    
    // brute force number of times to join
    for(int i = 0; i <= runs-1; i++) {
        int rem = runs-i;
        int cost = i*x;

        cost += rem*y;

        ans = min(ans, cost);
    }

    cout << ans << endl;
}

/*

consider runs of 0, better to join them all or fix them separately?

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
