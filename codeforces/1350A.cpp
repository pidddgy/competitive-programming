// https://codeforces.com/contest/1350/problem/0

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
        int n, k;
        cin >> n >> k;

        if(n%2 == 0) {
            cout << n + (2*k) << endl;
        } else {
            for(int i = 2; i <= n; i++) {
                if(n%i == 0) {
                    cout << n+i + (2*(k-1)) << endl;
                    break;
                }
            }
        }
    }
}