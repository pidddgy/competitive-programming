// https://codeforces.com/contest/294/problem/B

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

// widths of length i
vector<int> w[3];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int t_, w_;
        cin >> t_ >> w_;

        w[t_].emplace_back(w_);
    }

    for(int i = 1; i <= 2; i++) {
        sort(all(w[i]));
        reverse(all(w[i]));
    }

    int ans = LLONG_MAX;
    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= 100; j++) {
            if(sz(w[1]) < i) continue;
            if(sz(w[2]) < j) continue;

            int sum = 0;
            for(int k = i; k < sz(w[1]); k++) {
                sum += w[1][k];
            }

            for(int k = j; k < sz(w[2]); k++) {
                sum += w[2][k];
            }

            if(sum <= i + j*2) {
                ans = min(ans, i + j*2);
            }
        }
    }

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
