// https://codeforces.com/contest/1364/problem/0

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 100500;

int a[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, x;
        cin >> n >> x;

        int sum = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        int ans = -1;

        if(sum % x != 0) {
            ans = n;
        }

        int tmp = sum;
        for(int i = 1; i <= n; i++) {
            tmp -= a[i];
            if(tmp % x != 0) {
                ans = max(ans, n-i);
            }
        }

        tmp = sum;
        for(int i = n; i >= 1; i--) {
            tmp -= a[i];
            if(tmp % x != 0) {
                ans = max(ans, i-1);
            }
        }

        cout << ans << endl;

        for(int i = 1; i <= n; i++) {
            a[i] = 0;
        }
    }
}
