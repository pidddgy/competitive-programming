// https://codeforces.com/contest/1382/problem/0

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> S;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        S.emplace(x);
    }

    bool found = false;
    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;

        if(S.count(x) and !found) {
            cout << "YES" << endl;
            cout << 1 << " " << x << endl;
            found = true;
        }
    }

    if(!found) {
        cout << "NO" << endl;
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}
