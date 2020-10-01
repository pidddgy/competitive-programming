// https://codeforces.com/contest/1175/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int n, k;
        cin >> n >> k;

        int a[n+1];
        for(int i = 1; i <= n; i++) cin >> a[i];

        pii ans = pii(INT_MAX, INT_MIN);
        for(int i = 1; i+k <= n; i++) {
            int dist = a[i+k]-a[i];
            watch(dist)
            ans = min(ans, pii(dist, a[i]+dist/2));
        }

        cout << ans.se << endl;
    }
}
