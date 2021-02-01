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

const int maxn = 200500;

int a[maxn];
pii range[maxn];
void solve() {
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        range[i] = pii(0, 0);
    }

    range[1] = pii(a[1]+1, a[1]+1);
    cerr << range[1].fi << " " << range[1].se << endl;
    for(int i = 2; i <= n; i++) {
        // what is the lowest this one can go?
        range[i].fi = max(a[i]+1, range[i-1].fi-k+1);

        // highest can go?
        range[i].se = min(a[i]+k, range[i-1].se+k-1);

        if(range[i].fi > range[i].se) {
            cerr << "failed on " << i << endl;
            cout << "NO" << endl;
            return;
        }

        cerr << range[i].fi << " " << range[i].se << endl;
    }

    int end = a[n]+1;
    if(range[n].fi <= end and end <= range[n].se) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

implementation

greedily go from left to right, 

add to current i as long as we are not above the next height

cannot have two fences on one i, so we choose 1 height for each i

if a[i] >= a[i+1] we go as low as possible
if a[i] < a[i+1] we go as high as possible

maintain a possible range for each


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
