// https://codeforces.com/contest/809/problem/A
    
#include <bits/stdc++.h>
using namespace std;
#define int long long
    
const int MOD = 1000000007;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
    
signed main() {
    int n;
    cin >> n;
    
    int a[n+1];
    a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    sort(a+1, a+n+1);

    int prev = 0;    
    int ans = 0;
    int r = 0;
    for(int i = 2; i <= n; i++) {
        r *= 2;
        r++;
        r %= MOD;

        int diff = a[i]-a[i-1];
        diff %= MOD;

        prev = (prev*2);
        prev %= MOD;

        prev += ((r*diff) % MOD);
        prev %= MOD;

        ans += prev;
        ans %= MOD;

        // watch(ans)
    }
    cout << ans << endl;
    
}