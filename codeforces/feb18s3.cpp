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

int n;
pii a[maxn];

int f(int y) {
    int res = 0;
    for(int i = 1; i <= n; i++) {
        int loc = abs(a[i].fi-a[i].se);
        loc = min(loc, abs(a[i].fi) + abs(a[i].se-y));

        res += loc;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("teleport.in", "r", stdin); 
    freopen("teleport.out", "w", stdout);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    int ans = 1e18;

    int l = 0, r = 1e18;
    // bsearch for last element that is < previous
    while(l <= r) {
        int mid = (l+r)/2;
        cerr << "trying " << mid << endl;
        ans = min(ans, f(mid));
        if(f(mid) < f(mid-1)) {
            cerr << "up" << endl;
            l = mid+1;
        } else {
            cerr << "down" << endl;
            r = mid-1;
        }
    }

    l = 0, r = 1e18;
    // bsearch for first element that is < the next
    while(l <= r) {
        int mid = (l+r)/2;
        cerr << "trying " << mid << endl;
        ans = min(ans, f(-mid));
        if(f(-mid) < f(-(mid-1))) {
            cerr << "up" << endl;
            l = mid+1;
        } else {
            cerr << "down" << endl;
            r = mid-1;
        }
    }


    // for(int i = 1; i <= n; i++) {
        // for(int x: {a[i].fi, a[i].se, a[i].fi-1, a[i].fi+1, a[i].se-1, a[i].se+1}) {
            // if(x )
            // ans = min(ans, f(x));
        // }
    // }

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
