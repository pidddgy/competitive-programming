// https://codeforces.com/contest/1362/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    // cout << (1LL << 62) << endl;
    while(t--) {
        int n;
        cin >> n;

        int ans = 0;

        for(int i = 0; i <= 62; i++) {
            int c = (1LL << i);
            // if(c > n) continue;

            ans += (n)/(c);

        }

        cout << ans << endl;
    }
}
