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
    int n;
    cin >> n;

    deque<int> dq;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        dq.emplace_back(x);
    }

    int cur = 0;

    while(sz(dq)) {
        if(cur == 0) {
            cout << dq.front() << " ";
            dq.pop_front();
        } else {
            cout << dq.back() << " ";
            dq.pop_back();  
        }

        cur ^= 1;
    }

    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
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
