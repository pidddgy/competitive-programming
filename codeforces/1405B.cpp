// https://codeforces.com/contest/1405/problem/B

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

const int maxn = 100500;

int n;
int a[maxn];

void solve() {
    cin >> n;

    set<int> pos, neg;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] > 0) {
            pos.emplace(i);
        } else {
            neg.emplace(i);
        }
    }

    for(int i: pos) {
        if(neg.lower_bound(i) == neg.end()) break;

        while(a[i] and sz(neg) and neg.lower_bound(i) != neg.end()) {
            int j = *(neg.lower_bound(i));
            int take = min(abs(a[i]), abs(a[j]));
            
            a[i] -= take;
            a[j] += take;

            if(a[j] == 0) {
                neg.erase(neg.lower_bound(i));
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cerr << a[i] << " ";
    }
    cerr << endl;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] < 0) ans += -a[i];
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

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
