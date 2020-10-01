// https://codeforces.com/contest/1420/problem/B

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

const int maxn = 100500;

int n;
int a[maxn];
int cnt[100];

void solve() {
    cin >> n;

    for(int i = 0; i <= 35; i++) {
        cnt[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 35; j >= 0; j--) {
            if(a[i]&(1LL << j)) {
                cerr << "highest bit for " << a[i] << " is " << j << endl;
                ans += cnt[j];
                cnt[j]++;
                break;
            }
        }
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

for i in j
    take all numbers with the same highest set bit
    update counts

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
