// https://dmoj.ca/problem/dmopc20c1p6

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

const int maxn = 2005;

int a[maxn];
bool gacha[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        gacha[i] = true;
    }

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int l, r;
            cin >> l >> r;

            for(int i = l; i <= r; i++) {
                gacha[i] = true;
            }
        }

        if(t == 2) {
            int l, r;
            cin >> l >> r;

            for(int i = l; i <= r; i++) {
                gacha[i] = false;
            }
        }

        if(t == 3) {
            int l, r, x;
            cin >> l >> r >> x;

            for(int i = l; i <= r; i++) {
                a[i] = x;
            }
        }

        if(t == 4) {
            int l, r;
            cin >> l >> r;

            int run = 0;
            bool f = false;
            int ma = LLONG_MIN;
            for(int i = l; i <= r; i++) {
                if(gacha[i]) {
                    cerr << "adding " << a[i] << " to " << run << endl;
                    run += a[i];
                    if(!f) {
                        ma = run;
                    } else {
                        ma = max(ma, run);
                    }
                    f = true;
                } else {
                    run = 0;
                }
            }

            if(!f) {
                cout << "breaks galore" << endl;
            } else {
                cout << ma << endl;
            }
        }

        if(t == 5) {
            int l, r;
            cin >> l >> r;
            
            int run = 0;
            bool f = false;
            int ma = LLONG_MIN;
            for(int i = l; i <= r; i++) {
                if(!gacha[i]) {
                    run += a[i];
                    if(!f) {
                        ma = run;
                    } else {
                        ma = max(ma, run);
                    }
                    f = true;
                } else {
                    run = 0;
                }
            }

            if(!f) {
                cout << "breaks galore" << endl;
            } else {
                cout << ma << endl;
            }
        }
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