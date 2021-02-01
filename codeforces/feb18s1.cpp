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

const int maxl = (int)1e6+500;

int suf[maxl];
map<int, int> mp;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("reststops.in", "r", stdin); 
    freopen("reststops.out", "w", stdout);

    int L, N, rf, rb;
    cin >> L >> N >> rf >> rb;

    for(int i = 1; i <= N; i++) {
        int x, c;
        cin >> x >> c;

        suf[x] = max(suf[x], c);
        mp[x] = max(mp[x], c);
    }

    for(int i = 1e6; i >= 1; i--) {
        suf[i] = max(suf[i], suf[i+1]);
    }

    int ans = 0;
    // number of seconds
    int s = 0;
    for(int i = 1; i <= L; i++) {
        s += rf-rb;

        if(mp[i] == suf[i]) {
            ans += s*mp[i];
            s = 0;
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
