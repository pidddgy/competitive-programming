// https://codeforces.com/contest/1003/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define cerr if(false) cerr
#define endl '\n'
#define int long long

int cnt[35];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        int _;
        cin >> _;

        cnt[__builtin_ctz(_)]++;
    }

    while(q--) {
        int b;
        cin >> b;

        int ans = 0;
        for(int i = 30; i >= 0; i--) {
            int need = min(b >> i, cnt[i]);
            ans += need;
            b -= (1LL << i) * need;
        }

        if(b) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
}