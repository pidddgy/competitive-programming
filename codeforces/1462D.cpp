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


const int maxn = 3005;

int a[maxn];

void solve() {
    int n;
    cin >> n;

    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int ans = LLONG_MAX;
    for(int i = 1; i <= n; i++) {
        if(sum%i == 0) {
            int per = sum/i;

            int cur = 0;
            int loc = 0;
            int len = 0;

            for(int j = 1; j <= n; j++) {
                len++;
                cur += a[j];

                if(cur == per) {
                    loc += len-1;
                    cur = 0;
                    len = 0;
                }
            }

            if(cur == 0) {
                cerr << "divide into " << per << endl;
                ans = min(ans, loc);
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
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
