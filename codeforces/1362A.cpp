// https://codeforces.com/contest/1362/problem/0

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
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        int ans = 0;

        while(a*8 <= b) {
            a *= 8;
            ans++;
        }

        while(a*4 <= b) {
            a *= 4;
            ans++;
        }

        while(a*2 <= b) {
            a *= 2;
            ans++;
        }

        if(a == b) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
