// https://codeforces.com/contest/1354/problem/0

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
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int have = b;
        int rem = a-b;

        if(rem <= 0) {
            cout << b << endl;
            continue;
        }

        if(c <= d) {
            cout << -1 << endl;
            continue;
        }

        // rate == get each time
        int rate = c-d;
        int cost = c;

        int use = (rem+(rate-1)) / rate;

        cout << have+(use*cost) << endl;
    }
}
