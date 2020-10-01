// https://codeforces.com/contest/776/problem/C

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

int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int exp = 1;
    int ans = 0;
    
    for(int it = 1;; it++) {
        cerr << "on " << exp << endl;
        map<int, int> cnt;
        int sum = 0;
        int loc = 0;
        cnt[0] = 1;
        for(int i = 1; i <= n; i++) {
            sum += a[i];
            watch(sum)
            
            cerr << "getting cnt of " << sum-exp << endl;
            loc += cnt[sum-exp];

            cnt[sum]++;
        }

        cerr << exp << " contributes " << loc << endl;
        ans += loc;

        if(exp <= (int)1e18/abs(k)) {
            exp *= k;
        } else {
            break;
        }
        cerr << endl;

        if(k == 1) {
            break;
        }

        if(k == -1 and it == 2) break;
    }

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
