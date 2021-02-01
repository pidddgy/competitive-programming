// https://codeforces.com/contest/343/problem/C

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

int getcost(int a, int b, int x) {
    int ree = abs(x-a);
    if(x < b) ree += abs(a-b);

    int ree2 = abs(x-b);
    if(x > a) ree2 += abs(b-a);

    return min(ree, ree2);
}
int h[maxn], p[maxn];

int n, m;
bool ok(int x) {
    int ind = 1;
    cerr << "trying " << x << endl;

    for(int i = 1; i <= n; i++) {
        int l = min(h[i], p[ind]);
        int r = max(h[i], p[ind]);
        int cost = getcost(l, r, h[i]);
        if(cost > x) continue;
        ind++;
        
        while(ind <= m) {
            int nl = min(l, p[ind]);
            int nr = max(r, p[ind]);

            int c = getcost(nl, nr, h[i]);

            if(c <= x) {
                ind++;
                cost = c;
            } else break;
        }

        if(ind == m+1) break;
    }

    watch(ind)

    assert(ind <= m+1);
    return ind == m+1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> p[i];
    }

    int ans = LLONG_MAX;
    int l = 0, r = 1e18;

    while(l <= r) {
        int mid = (l+r)/2;

        if(ok(mid)) {
            ans = min(ans, mid);
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    assert(ans != LLONG_MAX);

    cout << ans << endl;
}

/*

binary search

keep track of leftmost element we haven't taken

for every head go to ind
go as far right as possible, update ind



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?