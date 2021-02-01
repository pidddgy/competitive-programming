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


map<int, int> dp;

int ops = 0;
int f(int n) {
    // if(n == 1) return 1;
    if(dp.count(n)) return dp[n];

    // cerr << "on " << n << endl;
    // beginning of range
    int lst = 2;

    int res = 0;

    int nxt = n/2;
    res += n-nxt;

    while(lst <= n/2) {
        int l = lst, r = n;
        int lgood = -1;

        while(l <= r) {
            int mid = (l+r)/2;

            if((n/mid) == (n/lst)) {
                lgood = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        assert(lgood != -1);

        if(n == 10)
        cerr << lst << " " << lgood << endl;
        res += f(n/lst) * ((lgood-lst)+1);


        // cerr << "setting lst to " << lgood+1 << endl;
        lst = lgood+1;
        ops++;
    }

    dp[n] = res;
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    dp[1] = 1;
    cout << f(n) << endl;

    // for(int i = 1; i <= n; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    // cout << ops << endl;
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