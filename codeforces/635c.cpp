// https://codeforces.com/contest/1335/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        set<int> S;
        int a[n+1];
        unordered_map<int, int> cnt;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            S.emplace(a[i]);
            cnt[a[i]]++;
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            // dont include
            ans = max(ans, min((int)S.size()-1, cnt[a[i]]));

            // include
            ans = max(ans, min((int)S.size(), cnt[a[i]]-1));
        }

        cout << ans << endl;
    }
}