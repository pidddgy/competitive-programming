// https://codeforces.com/contest/1165/problem/E

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int b[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    sort(b+1, b+n+1);
    
    int val[n+1];
    for(int i = 1; i <= n; i++) {
        val[i] = a[i] * i * ((n-i)+1);
    }

    sort(val+1, val+n+1, greater<int>());

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        ans += ((val[i]%MOD) * (b[i]%MOD))%MOD; 
        ans %= MOD;
    }

    cout << ans << endl;
}
