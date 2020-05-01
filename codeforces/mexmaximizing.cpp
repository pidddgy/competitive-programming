// https://codeforces.com/contest/1294/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
const int maqx = (4 * 1e5) + 300;

int cnt[maqx];
set<pii> S;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int q, x;
    cin >> q >> x;

    for(int i = 0; i < x; i++) {
        S.emplace(0, i);
    }

    for(int i = 1; i <= q; i++) {
        int y;
        cin >> y;

        S.erase(S.find({cnt[y%x], y%x}));
        cnt[y%x]++;
        S.emplace(cnt[y%x], y%x);

        pii mi = *S.begin();
        cout << (x * mi.fi) + mi.se << endl;
        
    }    
}