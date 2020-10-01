// https://codeforces.com/contest/1353/problem/C

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

    while(t--) {
        int n;
        cin >> n;

        int ans = 0;
        for(int i = 1; i <= n/2; i++) {
            ans += 8*i*i;
        }

        cout << ans << endl;
    }
}
