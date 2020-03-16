// https://codeforces.com/contest/1325/problem/C

#include <bits/stdc++.h>
    #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'
    int n;
    cin >> n;

    if(n == 2) {
        cout << 0 << endl;
        return 0;
    }

    vector<pii> G[n+1];
    
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;

        G[a].emplace_back(mp(b, i));
        G[b].emplace_back(mp(a, i));
    }

    // pick any leaf node
    int ans[n];
    for(int i = 0; i < n; i++) {
        ans[i] = -1;
    }

    int cur = 0;
    for(int st = 1; st <= n; st++) {
        if(G[st].size() == 1) {
            ans[G[st][0].se] = cur;
            cur++;
        }
    }

    for(int i = 0; i < n-1; i++) {
        if(ans[i] == -1) {
            cout << cur << endl;
            cur++;
        } else {
            cout << ans[i] << endl;
        }
    }
}