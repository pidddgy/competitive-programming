// https://codeforces.com/contest/1372/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int ans = (a[1] != 1);
        for(int i = 2; i <= n; i++) {
            if(a[i] != i and a[i-1] == i-1) {
                ans++;
            }
        }

        cout << ans << endl;
    }
}
