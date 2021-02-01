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

int n;
int a[maxn], b[maxn], c[maxn];
void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i];

        if(a[i] > b[i]) swap(a[i], b[i]);
    }

    int ans = 0;
    int len = 0;
    for(int i = 2; i <= n; i++) {
        if(i != 2) {
            len += a[i];
            len += c[i-1]-b[i]+1;
            if(a[i] == b[i]) len--;
        }

        if(a[i] == b[i]) {
            ans = max(ans, len);
            len = 1;
        }

        // cana lso choose to start a new cycle from last
        len = max(len, b[i]-a[i]+1);

        watch(len+c[i])
        // choose to end cycle right here
        ans = max(ans, len+c[i]);
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

walk across, keep length of current cycle

add last up/down

if connected to same, restart cycle
else add 

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
