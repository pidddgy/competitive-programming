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

void no() {
    cout << -1 << endl;
    exit(0);
}

const int maxn = 100500;

int n, m;
int a[maxn];
int ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int sum = 0;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int overlap = sum-n;

    if(overlap < 0) no();

    int last = 0;
    watch(overlap)
    for(int i = 1; i <= m; i++) {
        int take = min(overlap, a[i-1]-1);

        int cur = last+a[i-1]-take;
        if(cur+a[i]-1 > n) no();

        ans[i] = cur;
        last = cur;

        if(i > 1) {
            overlap -= take;
        }
        watch(overlap)
    }

    for(int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
