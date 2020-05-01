// https://codeforces.com/contest/1339/problem/C

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

        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        a[0] = a[1];
        
        int ma = -LLONG_MAX;
        int madiff = 0;
        for(int i = 1; i <= n; i++) {
            ma = max(ma, a[i]);
            if(ma > a[i]) {
                madiff = max(madiff, ma-a[i]);
            }
        }
        int mabit = 0;
        for(int i = 0; i < 35; i++) {
            if(madiff & (1LL<<i)) {
                mabit = i+1;
            }
        }

        cout << mabit << endl;

    }
}