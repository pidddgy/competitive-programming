// https://codeforces.com/contest/856/problem/A

#include <bits/stdc++.h>
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
        if(n == 1) {
            cout << "YES" << endl;
            cout << 1 << endl;
            int _;
            cin >> _;
        } else {
            int a[n+1];
            for(int i = 1; i <= n; i++) {
                cin >> a[i];
            }

            sort(a+1, a+n+1);

            int mi = INT_MAX;
            for(int i = 2; i <= n; i++) {
                mi = min(mi, a[i]-a[i-1]+1);
            }

            if(mi >= n) {
                cout << "YES" << endl;
                for(int i = 1; i <= n; i++) {
                    cout << i << " ";
                }
                cout << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}