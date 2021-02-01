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

    priority_queue<int> pq[2];

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        pq[x%2].push(x);
    }

    vector<int> v(2);
    int turn = 0;
    while(sz(pq[0]) or sz(pq[1])) {
        int take = -1e18;
        int deny = -1e18;

        if(sz(pq[turn])) take = pq[turn].top();
        if(sz(pq[turn^1])) deny = pq[turn^1].top();

        if(take >= deny) {
            pq[turn].pop();
            v[turn] += take;
        } else {
            pq[turn^1].pop();
        }

        turn ^= 1;
    }

    if(v[0] == v[1]) {
        cout << "Tie" << endl;
    } else if(v[0] > v[1]) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

either add or deny the other

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
