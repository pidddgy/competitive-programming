// https://codeforces.com/contest/363/problem/D

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

int b[maxn], p[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a;
    cin >> n >> m >> a;

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> p[i];
    }

    sort(b+1, b+n+1, greater<int>());
    sort(p+1, p+m+1);

    int l = 0;
    int r = min(n, m);

    pii ans = {0, 0};
    while(l <= r) {
        int mid = (l+r)/2;
        bool ok = true;
        int need = 0, personal = 0;
        for(int i = 1; i <= mid; i++) {
            need += max(0LL, p[i]-b[mid-i+1]);
            personal += min(p[i], b[mid-i+1]);
        }

        if(need <= a) {
            int leftover = a-need;
            ans = pii(mid, max(0LL, personal-leftover));
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cout << ans.fi << " " << ans.se << endl;
}

/*

sort the boys in non increasing order of money
sort bikes in increasing order by price

the bikes we buy are always a prefix (exchange: if optimal solution uses a more expensive bike we can swap)
the boys that get to ride are prefix of same length (exchange: if we use a boy with less money we can use a boy with more money)

binary search

to check loop over all the boys and give them money if they need it

the boy with least money gets the cheapest bike. if the boy with least money cannot get the cheapest bike then he for sure can't get any other bike.

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
