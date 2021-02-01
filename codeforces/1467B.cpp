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

const int maxn = 300500;

int n;
int a[maxn];
int pre[maxn], suf[maxn];

int check(int i) {
    if(i <= 1 or i >= n) return 0;
    return (a[i] < a[i-1] and a[i] < a[i+1]) or (a[i] > a[i-1] and a[i] > a[i+1]);
}
void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int cur = 0;
    for(int i = 1; i <= n+5; i++) {
        if(i < n)
        if(check(i)) {
            cur++;
        }

        pre[i] = cur;
    }

    cur = 0;

    for(int i = n+5; i >= 1; i--) {
        if(i > 1)
        if(check(i)) {
            cur++;
        }

        suf[i] = cur;
    }

    int ans = pre[n];

    for(int i = 2; i <= n-1; i++) {
        int cpy = a[i];
        for(int x: set<int>({(int)-1e18, (int)1e18, a[i-1], a[i+1]})) {
            a[i] = x;
            ans = min(ans, pre[i-2]+check(i-1)+check(i)+check(i+1)+suf[i+2]);
        }
        a[i] = cpy;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--) solve();
}

/*

prefix/suffix + 1 if it is a valley
        ans = min(ans, pre[i-2]+check(i-1)+check(i)+check(i+1)+suf[i+2]);

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
