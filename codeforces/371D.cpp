// https://codeforces.com/contest/371/problem/D

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

const int maxn = 200500;
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<pii> S;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        S.emplace(i, a[i]);
    }

    int m;
    cin >> m;

    for(int i = 1; i <= m; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            int p, x;
            cin >> p >> x;

            while(x) {
                auto ptr = S.lower_bound(pii(p, INT_MIN));
                if(ptr == S.end()) break;


                pii val = *ptr;

                int take = min(x, val.se);

                cerr << "taking " << take << " from " << val.fi << " " << val.se << endl;

                x -= take;
                S.erase(ptr);

                if(val.se > take) {
                    S.emplace(val.fi, val.se-take);
                }
            }
        } else if(t == 2) {
            cerr << "a" << endl;
            int k;
            cin >> k;

            auto ptr = S.lower_bound(pii(k, INT_MIN));
            if(ptr == S.end()) {
                cout << a[k] << endl;
            } else {
                pii val = *ptr;
                cerr << val.fi << " " << val.se << endl;
                if(val.fi > k) {
                    cout << a[k] << endl;
                } else {
                    cout << a[k]-val.se << endl;
                }
            }
        }
    }
}

/*

represent each vessel as the capacity it has left

simulate with set

set<pii> S

.fi = ind;
.se = capacity

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
