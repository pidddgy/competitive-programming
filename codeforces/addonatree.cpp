// https://codeforces.com/contest/1188/problem/A1

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define watch(x) cerr << (#x) << " is " << (x) << endl;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<int> G[n+1];
    for(int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
        G[v].emplace(u);
    }

    for(int i = 1; i <= n; i++) {
        cerr << "on " << i << endl;
        if(G[i].size() == 2) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}