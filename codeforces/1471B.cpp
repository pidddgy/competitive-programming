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

const int maxn = 100500;

int a[maxn];
int n, x;
int ans = 0;

void solve() {
    ans = 0;
    cin >> n >> x;

    bool ree = false;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i]%x) ree = true;
    }
    bool hit = false;
    for(int i = 1; i <= n; i++) {
        int cnt = 1;
        int cpy = a[i];

        if(i == 1 and !ree) {
            for(;;) {
                cerr << cnt << " copies of " << a[i] << endl;
                ans += a[i]*cnt;

                if(a[i] % x) {
                    break;
                }
            
                a[i] /= x;
                cnt *= x;
            }
        } else {
            cerr << "adding " << a[i] << endl;
            ans += a[i];
            if(a[i] % x == 0 and !hit) {
                ans += x*(a[i]/x);
            }
        }

        if(cpy%x) hit = true;

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

keep pushing elements and adding them
when hit one that isnt divisible, we can push new elements but they no longer do anything

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?