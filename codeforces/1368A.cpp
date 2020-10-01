// https://codeforces.com/contest/1368/problem/0

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
        int a, b, n, A, B;
        cin >> A >> B >> n;
        int ans = INT_MAX;

        a = A;
        b = B;
        int cnt = 0;
        while(!(a > n || b > n)) {
            if(cnt % 2 == 0) {
                a += b;
            } else {
                b += a;
            }
            cnt++;
        }

        ans = min(ans, cnt);

        a = A;
        b = B;
        cnt = 0;
        while(!(a > n || b > n)) {
            if(cnt % 2 == 0) {
                b += a;
            } else {
                a += b;
            }

            cnt++;
        }

        ans = min(ans, cnt);

        cout << ans << endl;
    }
}
