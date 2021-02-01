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

int n,m;
int a[maxn], b[maxn];
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
    sort(b+1, b+m+1);

    if(a[n] < b[m]) {
        for(int i = 1; i <= max(n, m); i++) {
            swap(a[i], b[i]);
        }
        swap(n, m);
    }

    int sum = 0;
    for(int i = 1; i <= m; i++) {
        sum += b[i];
    }

    int ans = sum;

    for(int i = 1; i <= n-1; i++) {
        ans += min(sum, a[i]);
    }

    cout << ans << endl;
}

/*

no point in copying an element more than once

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
