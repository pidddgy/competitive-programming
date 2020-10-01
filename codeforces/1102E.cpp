// https://codeforces.com/contest/1102/problem/E

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 200500;
const int MOD = 998244353;

int a[maxn];
int b[maxn];
map<int, pii> border;
set<int> elems;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        elems.emplace(a[i]);

        if(border[a[i]] == pii(0LL, 0LL)) {
            border[a[i]] = pii(i, i);
        } else {
            border[a[i]].se = max(border[a[i]].se, i);
        }
    }

    for(int x: elems) {
        b[border[x].fi]++;
        b[border[x].se]--;
    }
    
    int cur = 0;
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        if(cur == 0 and i != 1) {
            ans *= 2;
            ans %= MOD;
        }
        cur += b[i];
    }

    cout << ans << endl;
}