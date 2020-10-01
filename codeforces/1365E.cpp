// https://codeforces.com/contest/1365/problem/E

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

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

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                ans = max(ans, a[i]|a[j]|a[k]);
            }
        }
    }

    cout << ans << endl;
}


