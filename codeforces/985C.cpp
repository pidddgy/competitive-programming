// https://codeforces.com/contest/985/problem/C

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

int a[100500];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, l;
    cin >> n >> k >> l;

    for(int i = 1; i <= n*k; i++) {
        cin >> a[i];
    }

    sort(a+1, a+n*k+1);
    // a[1] must be a deciding stave so it is bounded by that
    int lim = a[1]+l;
    vector<int> v;
    int ans = 0;
    int b = 0;
    for(int i = n*k; i >= 1; i--) {
        if(a[i] <= lim and sz(v) >= k-1) {
            for(int j = 1; j <= k-1; j++) {
                v.pop_back();
            }
            ans += a[i];
            b++;
        } else {
            v.push_back(a[i]);
        }
    }

    if(b < n) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
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
