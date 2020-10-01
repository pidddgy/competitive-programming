// https://codeforces.com/contest/446/problem/A

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

const int maxn = 100500;

int n;
int a[maxn], l[maxn], r[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        l[i] = l[i-1]+1;
        if(a[i] <= a[i-1]) l[i] = 1;
    }

    for(int i = n; i >= 1; i--) {
        r[i] = r[i+1]+1;
        if(a[i] >= a[i+1]) r[i] = 1;
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        ans = max(ans, l[i]+1);
    }

    ans = max(ans, l[n]);

    for(int i = n; i >= 2; i--) {
        ans = max(ans, r[i]+1);
    }

    ans = max(ans, r[1]);

    for(int i = 2; i <= n-1; i++) {
        if(a[i-1]+1 < a[i+1]) {
            ans = max(ans, l[i-1]+1+r[i+1]);
        }
    }

    ans = min(ans, n);

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
