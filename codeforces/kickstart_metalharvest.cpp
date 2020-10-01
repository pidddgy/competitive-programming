// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff48/00000000003f4ed8

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

void solve() {
    int n, k;
    cin >> n >> k;

    // last -> we have harvested all ranges before x
    int last = -1;
    int ans = 0;
    vector<pii> shit;

    for(int i = 1; i <= n; i++) {
        int s, e;
        cin >> s >> e;

        shit.emplace_back(s, e);
    }

    sort(all(shit));
    for(pii fuck: shit) {
        int s = fuck.fi, e = fuck.se;
        int lb = max(s, last);

        int l = 0, r = 1e9;
        int lgood = -1;
        while(l <= r) {
            int md = (l+r)/2;

            int ree = lb + md*k;

            if(ree >= e) {
                lgood = md;
                r = md-1;
            } else {
                l = md+1;
            }
        }

        ans += lgood;
        last = lb + lgood*k;
        cerr << "using " << lgood << " from " << lb << " takes us to " << last << endl;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++) {
        cout << "Case #"<<tc << ": ";
        solve();
        // cout << endl;
    }
}

/*

1
1 4
1 4

-> 1

1 
4 7
1 2
2 3
4 6
8 9

-> 2

1 
3 7
1 2
2 3
4 6

1 
3 3
1 2
2 3
3 4


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
