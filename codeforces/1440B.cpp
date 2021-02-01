// https://codeforces.com/contest/1440/problem/B

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
    int n, k;
    cin >> n >> k;

    deque<int> dq;

    for(int i = 1; i <= n*k; i++) {
        int x;
        cin >> x;

        dq.push_back(x);
    }
    int f,b;
    if(n&1) {
        f = n/2;
        b = n-f;
    } else {
        f = n/2-1;
        b = n-f;
    }

    // if(n == 2) {
    //     f = n;
    //     b = 0;
    // }

    watch(f)
    watch(b)

    int ans = 0;
    for(int i = 1; i <= k; i++) {
        vector<int> cur;

        

        for(int j = 1; j <= f; j++) {
            assert(sz(dq));
            cur.push_back(dq.front());
            dq.pop_front();
        }

        vector<int> tmp;
        for(int j = 1; j <= b; j++) {
            assert(sz(dq));
            tmp.push_back(dq.back());
            dq.pop_back();
        }

        reverse(all(tmp));
        for(int x: tmp) cur.push_back(x);

        for(int x: cur) {
            cerr << x << " ";
        }
        cerr << endl;

        ans += cur[(sz(cur)-1)/2];
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
        cerr << "~~~~~~" << endl << endl;
    }
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
