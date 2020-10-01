// https://codeforces.com/contest/1406/problem/B

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

const int maxn = 200500;

int a[maxn];

void solve() {
    int n;
    cin >> n;

    vector<int> pos, neg;    
    bool zero = false;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] > 0) {
            pos.emplace_back(a[i]);
        } else if(a[i] < 0) {
            neg.emplace_back(a[i]);
        }

        if(a[i] == 0) zero = true;
    }

    // must have too many zeroes
    if(sz(pos)+sz(neg) < 5) {
        cout << 0 << endl;
        return;
    }

    sort(all(pos), greater<int>());
    sort(all(neg));

    int ans = LLONG_MIN;
    if(zero) ans = 0;

    for(int i = 0; i <= 5; i++) {
        int prod = 1;
        watch(i)
        
        if(i > sz(pos)) continue;
        for(int j = 0; j < i; j++) {
            prod *= pos[j];
        }

        int take = (5-i);
        if((take) > sz(neg)) continue;

        if(take & 1) {
            for(int j = 0; j < take; j++) {
                prod *= neg[sz(neg)-j-1];
            }
        } else {
            for(int j = 0; j < take; j++) {
                prod *= neg[j];
            }
        }
   

        ans = max(ans, prod);
    }

    cout << ans << endl;

    for(int i = 1; i <= n; i++) a[i] = 0;
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
