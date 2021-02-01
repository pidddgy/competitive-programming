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

const int maxn = 100500;

int a[maxn];
void solve() {
    int n, x;
    cin >> n >> x;

    int sum = 0;
    int ma = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];

        ma += (a[i] + x-1) / x;
    }

    cout << (sum+x-1)/x << " " << ma << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

combining will always reduce

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
