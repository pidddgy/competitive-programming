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

void solve() {
    
}

const int maxn = 200500;

int a[maxn];
int d[maxn];
int m, n, k, t;

int l[maxn], r[maxn], danger[maxn];
bool ok(int ind) {
    for(int i = 0; i < maxn; i++) {
        d[i] = 0;
    }    

    for(int i = 1; i <= k; i++) {
        if(danger[i] > a[ind]) {
            d[l[i]]++;
            d[r[i]+1]--;
        }
    }

    int time = n+1;
    for(int i = 1; i <= 2e5; i++) {
        d[i] += d[i-1];

        if(d[i]) {
            time += 2;
        }
    }

    return time <= t;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k >> t;

    for(int i = 1; i <= m; i++) {
        cin >> a[i];
    }    

    sort(a+1, a+m+1, greater<int>());

    for(int i = 1; i <= k; i++) {
        cin >> l[i] >> r[i] >> danger[i];
    }

    int l = 1;
    int r = m;

    int ans = 0;
    while(l <= r) {
        int mid = (l+r)/2;

        if(ok(mid)) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cout << ans << endl;
}

/*

bsearch on answer

each trap matters or it doesnt
should you go back and get squad before disabling trap?

each trapped square is traversed 3 times, every other is traversed once

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
