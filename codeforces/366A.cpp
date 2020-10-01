// https://codeforces.com/contest/366/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int one = 0, two = 0;
    int cost = INT_MAX;
    int ans = 0;
    for(int i = 1; i <= 4; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int C = min(a, b) + min(c, d);

        if(C < cost) {
            ans = i;
            cost = C;
            one = min(a, b);
            two = min(c, d);
        }
    }

    if(cost <= n) {
        cout << ans << " " << one << " " << n-one << endl;
    } else {
        cout << -1 << endl;
    }
}