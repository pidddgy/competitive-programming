// https://codeforces.com/contest/846/problem/F

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

const int maxn = (int)1e6+400;

int lst[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    // for(int i = 0; i < maxn; i++) lst[i] = 1;

    cout << fixed << setprecision(10);

    int n;
    cin >> n;

    int tot = 0;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        cerr << "calculating " << i << endl;
        cerr << "l choices are " << (i-lst[a]) << ", right choices are " << n-i+1 << endl;
        tot += 2*(i-lst[a]) * (n-i+1) - 1;
        lst[a] = i;
    }

    int pairs = n*n;

    ld ans = (1.0 * tot) / pairs;

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
