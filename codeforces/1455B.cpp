// https://codeforces.com/contest/1455/problem/B

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

int trng(int x) {
    return (x*(x+1))/2;
}

void solve() {
    int x;
    cin >> x;    

    int l = 1;
    int r = 1e6;
    int lgood = -1;
    int at = -1;
    while(l <= r) {
        int mid = (l+r)/2;

        if(trng(mid) >= x) {
            lgood = mid;
            at = trng(lgood);
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    
    int ans = lgood;
    
    int d = at-x;
    if(d == 1) {
        ans++;
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

triangular number
replace some numbers with -1

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
