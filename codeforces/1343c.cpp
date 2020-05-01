// https://codeforces.com/contest/1343/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a[n+1];
        a[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int sum = 0;
        int ma = a[1];
        for(int i = 2; i <= n; i++) {
            if(a[i] < 0 and !(a[i-1] < 0)) {
                sum += ma;
                ma = a[i];
            } else if(a[i] > 0 and !(a[i-1] > 0)) {
                sum += ma;
                ma = a[i];
            }

            ma = max(ma, a[i]);
        }
        sum += ma;

        cout << sum << endl;
    }
}