// https://codeforces.com/contest/500/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int w[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    int b[m+1];
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    int ans = 0;

    for(int i = 1; i <= m; i++) {
        bool added[n+1];
        for(int j = 1; j <= n; j++) added[j] = false;

        for(int j = i-1; j >= 1; j--) {
            if(b[i] == b[j]) break;
            if(added[b[j]]) continue;

            ans += w[b[j]];
            added[b[j]] = true;
        }
    }

    cout << ans << endl;
}