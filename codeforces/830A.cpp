// https://codeforces.com/problemset/problem/830/A

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

const int maxn = 2200;
int n, k, p;
int a[maxn], b[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> p;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= k; i++) {
        cin >> b[i];
    }

    sort(a+1, a+n+1);
    sort(b+1, b+k+1);

    int ans = INT_MAX;
    for(int i = 1; i+n-1 <= k; i++) {
        int loc = 0;
        for(int j = 1; j <= n; j++) {
            loc = max(loc, abs(a[j]-b[i+j-1]) + abs(b[i+j-1] - p));
        }

        ans = min(ans, loc);
    }
    
    cout << ans << endl;
}

/*

problem type: greedy


alt solution:

brute force n length subsegments

pair leftmost person with lefmost key and so on
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?