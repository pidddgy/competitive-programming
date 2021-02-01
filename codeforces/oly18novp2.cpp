// https://dmoj.ca/problem/oly18novp2

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

const int maxn = (int)1e6+50;

vector<int> a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int d, p;
        cin >> d >> p;

        a[d].emplace_back(p);
    }

    priority_queue<int> pq;

    int ans = 0;
    for(int i = 1e6; i >= 1; i--) {
        for(int x: a[i]) {
            pq.push(x);
        }

        if(sz(pq)) {
            ans += pq.top();
            pq.pop();
        }
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
