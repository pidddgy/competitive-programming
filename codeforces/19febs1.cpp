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
    
}

const int maxn = 100500;

int a[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a+1, a+n+1);

    for(int i = 1; i <= n; i++) cerr << a[i] << " ";
    cerr << endl;
    int ans = 1e18;
    int ans2 = -1e18;
    for(int i = 1; i <= n; i++) {
        int l = i, r = n;
        int lg = -1;
        while(l <= r) {
            int m = (l+r)/2;
            if(a[m]-a[i]+1 <= n) {
                lg = m;
                l =m+1;
            } else {
                r=m-1;
            }
        }

        cerr << i << " " << lg << endl;
        watch(lg-i+1)
        ans = min(ans, n-(lg-i+1));
        ans2 = max(ans2, n-(lg-i+1));
    }

    cout << ans << endl << ans2 << endl;
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
