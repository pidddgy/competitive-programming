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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("pairup.in", "r", stdin); 
    freopen("pairup.out", "w", stdout);

    deque<pii> dq;

    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        int x,y;
        cin >> x >> y;

        dq.push_back(pii(y, x));
    }

    sort(all(dq));

    int ans = 0;
    while(sz(dq)) {
        if(sz(dq) == 1) {
            ans = max(ans, 2*dq.front().fi);
            break;
        }

        ans = max(ans, dq.front().fi + dq.back().fi);

        int mi = min(dq.front().se, dq.back().se);

        dq.front().se -= mi;
        dq.back().se -= mi;

        if(dq.front().se == 0) dq.pop_front();
        if(dq.back().se == 0) dq.pop_back();
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
