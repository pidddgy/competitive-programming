// https://codeforces.com/problemset/problem/1336/B

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

set<int> S[10];

int sq(int num) {
    return 1LL*num*num;
}

void solve() {
    int nr, ng, nb;
    cin >> nr >> ng >> nb;

    for(int i = 1; i <= nr; i++) {
        int r;
        cin >> r;

        S[1].emplace(r);
    }

    for(int i = 1; i <= ng; i++) {
        int g;
        cin >> g;

        S[2].emplace(g);
    }

    for(int i = 1; i <= nb; i++) {
        int b;
        cin >> b;

        S[3].emplace(b);
    }

    cerr << "a" << endl;
    int ans = LLONG_MAX;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            for(int k = 1; k <= 3; k++) {
                if(sz(set<int>({i, j, k})) != 3) continue;

                cerr << i << " " << j << " " << k << endl;
                for(int x: S[j]) {
                    if((*S[i].begin()) > x) continue;
                    if(S[k].lower_bound(x) == S[k].end()) continue;

                    int l;
                    auto ptr = S[i].lower_bound(x);

                    if(ptr == S[i].end()) l = *S[i].rbegin();
                    else {
                        while((*ptr) > x and (ptr != S[i].begin())) {
                            ptr--;
                        }
                        l = *ptr;
                    }

                    int r = *(S[k].lower_bound(x));

                    cerr << l << " " << x << " " << r << endl;

                    ans = min(ans, sq(l-x) + sq(x-r) + sq(r-l));
                }
                cerr << endl;
            }
        }
    }

    cout << ans << endl;

    for(int i = 1; i <= 3; i++) {
        S[i].clear();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    // watch(t)
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