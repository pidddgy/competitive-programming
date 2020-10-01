// https://codeforces.com/contest/573/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 100500;

int n, h[maxn], l[maxn], r[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for(int i = 1; i <= n; i++) {
        l[i] = min(l[i-1]+1, h[i]);
    }

    for(int i = n; i >= 1; i--) {
        r[i] = min(r[i+1]+1, h[i]);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        ans = max(ans, min(l[i], r[i]));
    }

    cout << ans << endl;
}