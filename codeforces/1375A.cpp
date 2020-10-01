// https://codeforces.com/contest/1375/problem/0

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

        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for(int i = 1; i <= n; i++) {
            if(i&1) {
                cout << abs(a[i]) << " ";
            } else {
                cout << -abs(a[i]) << " ";
            }
        }
        cout << endl;
    }
}
