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

const int maxn = 200500;

int n, k;
int a[maxn], c[maxn];
vector<int> v[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= k; i++) {
        cin >> c[i];
    }

    sort(a+1, a+n+1);

    int ans = 0;

    for(int i = 1; i <= k; i++) {
        int l = 1;
        int r = n;
        int lg = -1;

        // find lefmost element >= x
        while(l <= r) {
            int mid = (l+r)/2;

            if(a[mid] >= i) {
                lg = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        if(lg == -1) continue;

        cerr << i << " -> " << ((n-lg+1) + c[i]-1)/c[i] << endl;
        watch(n-lg+1)
        watch(lg)
        ans = max(ans, ((n-lg+1) + c[i]-1)/c[i]);
    }

    int cur = 1;
    for(int i = 1; i <= n; i++) {
        v[cur].emplace_back(a[i]);

        cur++;
        if(cur == ans+1) cur = 1;
    }   

    cout << ans << endl;
    for(int i = 1; i <= ans; i++) {
        cout << sz(v[i]) << " ";
        for(int x: v[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}

/*

repeatedly bsearch to find number of test cases needed
evenly distribute

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
