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
#define sz(a) (int)(a).size()
#define y1 lsdjkfhshfdsighoihweogihewoghi
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 25;

int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int mask = 0; mask <= (1<<n)-1; mask++) {
        vector<int> v;

        int cur = 0;
        for(int i = 1; i <= n; i++) {
            cur += a[i];
            if(mask & (1 << (i-1))) {
                v.emplace_back(cur);
                cur = 0;
            }
        }

        if(cur) {
            v.emplace_back(cur);
        }

        bool inc = false;
        bool ok = true;

        for(int i = 1; i < sz(v); i++) {
            if(v[i] > v[i-1]) {
                inc = true;
            }

            if(!inc) {

            } else if(inc) {
                if(!(v[i] >= v[i-1])) ok = false;
            }
        }

        if(ok and sz(v) > ans) {
            ans = max(ans, sz(v));
            for(int x: v) {
                cerr << x << " ";
            }
            cerr << endl;
        }
    }

    cout << ans << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
