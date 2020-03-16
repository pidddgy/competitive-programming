// https://codeforces.com/contest/1307/problem/0

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, d;
        cin >> n >> d;

        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        int ans = a[1];
        for(int i = 2; i <= n; i++) {
            int dis = i-1;
            ans += min(a[i], d/dis);
            // cout << "on " << i << endl;
            // cout << "adding " << min(a[i], d/dis) << endl;

            d -= min(a[i], d/dis) * dis;
            // for(int j = 1; j <= a[i]; j++) {
            //     if(d >= i-1) {
            //         d -= i-1;
            //         ans++;
            //         a[j]--;
            //     } else {
            //         break;
            //     }
            // }
        }

        cout << ans << endl;
    }
}