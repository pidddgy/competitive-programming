// https://codeforces.com/contest/913/problem/D

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

const int maxn = 200500;

pii a[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, T;
    cin >> n >> T;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    int l = 0;
    int r = n;

    vector<int> ans;
    while(l <= r) {
        int m = (l+r)/2;

        vector<pii> probs;
        for(int i = 1; i <= n; i++) {
            if(a[i].fi >= m) {
                probs.emplace_back(a[i].se, i);
            }
        }

        sort(all(probs));

        vector<int> loc;
        int sum = 0;
        for(int i = 0; i < min((int)probs.size(), m); i++) {
            loc.emplace_back(probs[i].se);
            sum += probs[i].fi;
        }

        if(loc.size() == m and sum <= T) {
            ans = loc;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    cout << ans.size() << endl << ans.size() << endl;
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
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
