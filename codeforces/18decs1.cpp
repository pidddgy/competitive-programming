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
int n, m, c;

int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    cin >> n >> m >> c;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a+1, a+n+1);

    int l = 0, r = 1e9;
    int ans = 0;
    while(l <= r) {
        int mid = (l+r)/2;

        int bus = 0;
        int lst = -1;

        cerr << "trying " << mid << endl;
        for(int i = 1; i <= n; i++) {
            if(lst == -1) {
                bus++;
                lst = i;
                cerr << "start on " << i << endl;
            } else {
                if(a[i]-a[lst] > mid or i-lst >= c) {
                    bus++;
                    lst = i;
                    cerr << "start on " << i << endl;
                }
            }
        }

        watch(bus)
        cerr << endl;

        if(bus <= m) {
            r = mid-1;
            ans = mid;
        } else {
            l = mid+1;
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
