// https://codeforces.com/contest/845/problem/D

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
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    stack<int> S;

    int speed = 1;
    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        int t, x;
        cin >> t;
        if(t == 1) {
            cin >> x;
            speed = x;
        } else if(t == 2) {
            ans += cnt;
            cnt = 0;
        } else if(t == 3) {
            cin >> x;
            S.push(x);
        } else if(t == 4) {
            cnt = 0;
        } else if(t == 5) {
            while(S.size()) S.pop();
        } else if(t == 6) {
            cnt++;
        }

        while(S.size() and S.top() < speed) {
            S.pop();
            ans++;
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
