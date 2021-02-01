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
    int x;cin>>x;
    int ans = LLONG_MAX;
    for(int i = 0; i < (1<<9); i++) {
        int sum = 0;
        string loc = "";
        for(int j = 1; j <= 9; j++) {
            if(i & (1<<(j-1))) {
                sum += j;
                            char e = j+'0';
            loc += e;
            }
        }

        cerr << loc << " " << sum << endl;

        if(sum == x) {
            int ree = stoi(loc);

            ans = min(ans, ree);
        }
    }

    if(ans == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
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
