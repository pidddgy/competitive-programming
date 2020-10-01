// https://codeforces.com/contest/1141/problem/E

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int H, n;
    cin >> H >> n;

    int a[n+1];
    a[0] = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        int fsum = -sum;

        if(fsum >= H) {
            cout << i << endl;
            return 0;
        }
    }

    if(sum == 0) {
        cout << -1 << endl;
        return 0;
    }

    int ans = LLONG_MAX;
    int curSum = 0;
    for(int i = 0; i <= n; i++) {
        curSum += a[i];

        int rem = H+curSum;

        watch(rem)

        int fsum = -sum;
        int need = (rem+(fsum-1))/(fsum);
        watch(need)

        if(need >= 0) {
            ans = min(ans, need*n+i);
        }
    }

    if(ans == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
