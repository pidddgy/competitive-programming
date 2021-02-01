// https://dmoj.ca/problem/dmopc20c1p3

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

const int maxn = 500500;

int a[maxn], pre[maxn], suf[maxn];
int pma[maxn], sma[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ma = LLONG_MIN;
    for(int i = 1; i <= n; i++) {
        ma = max(ma, a[i]);
        pma[i] = ma;
    }

    ma = LLONG_MIN;
    for(int i = n; i >= 1; i--) {
        ma = max(ma, a[i]);
        sma[i] = ma;
    }

    for(int i = 2; i <= n; i++) {
        pre[i] = pre[i-1];
        pre[i] += max(0LL, pma[i-1]-a[i]);
    }


    for(int i = n-1; i >= 1; i--) {
        suf[i] = suf[i+1];
        suf[i] += max(0LL, sma[i+1]-a[i]);
    }

    int ans = 1e18;

    ans = min({pre[n], suf[1]});
    for(int i = 1; i <= n; i++) {
        int loc = 0;

        loc += max({0LL, pma[i-1]-a[i], sma[i+1]-a[i]});
        loc += pre[i-1];
        loc += suf[i+1];

        ans = min(ans, loc);
        cerr << "trying " << i << ", loc = " << loc << endl;
    }

    cout << ans << endl;
}

/*

brute force making each element the peak

cost to make prefix non decrasing

cost to make suffix non increasing

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?