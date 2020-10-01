// https://codeforces.com/contest/1394/problem/A

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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d, m;
    cin >> n >> d >> m;

    deque<int> big, small;
    int days = n, sum = 0, ans = 0;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        if(x > m) {
            big.emplace_back(x);
        } else {
            small.emplace_back(x);
            sum += x;
            days--;
        }
    }

    sort(all(big));
    sort(all(small));

    ans = sum;

    while(sz(small)) {
        // take as many big as possible
        while(days > 0 and sz(big)) {
            sum += big.back();
            ans = max(ans, sum);
            big.pop_back();
            days -= d+1;
        }

        sum -= small.front(); small.pop_front();
        days++;
    }

    while(days > 0 and sz(big)) {
        sum += big.back();
        ans = max(ans, sum);
        big.pop_back();
        days -= d+1;
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
