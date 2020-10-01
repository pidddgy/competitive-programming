// https://codeforces.com/contest/439/problem/D

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

int n, m;
int a[maxn], b[maxn];
int psa[maxn], psb[maxn];

int go(int x) {
    int res = 0;

    int l = 1, r = n;
    int lgood = -1;

    while(l <= r) {
        int mid = (l+r)/2;

        if(a[mid] < x) {
            lgood = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    
    if(lgood != -1)
        res += lgood*x - psa[lgood];

    l = 1, r = m;
    lgood = -1;

    while(l <= r) {
        int mid = (l+r)/2;

        if(b[mid] > x) {
            lgood = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    if(lgood != -1)
        res += psb[lgood] - lgood*x;

    return res;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    sort(a+1, a+n+1);
    sort(b+1, b+m+1, greater<int>());

    for(int i = 1; i <= n; i++) {
        psa[i] = psa[i-1]+a[i];
    }

    for(int i = 1; i <= m; i++) {
        psb[i] = psb[i-1]+b[i];
    }

    int ans = LLONG_MAX;
    
    for(int i = -1; i <= 1; i++) {
        for(int j = 1; j <= n; j++) {
            ans = min(ans, go(a[j]+i));
        }
        for(int j = 1; j <= m; j++) {
            ans = min(ans, go(b[j]+i));
        }
    }
    cout << ans << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
