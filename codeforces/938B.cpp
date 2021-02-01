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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> dq;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        dq.push_back(x);
    }

    for(int i = 1; i <= 2e6; i++) {
        while(sz(dq)) {
            if(dq.front()-1 <= i) {
                dq.pop_front();
            } else break;
        }

        while(sz(dq)) {
            if(1e6-dq.back() <= i) {
                dq.pop_back();
            } else break;
        }

        if(dq.empty()) {
            cout << i << endl;
            break;
        }
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
