// https://codeforces.com/contest/1342/problem/0

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
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        if(a*2 <= b) {
            cout << (x+y)*a << endl;
        } else {
            int ans = min(x,y) * b;

            ans += abs(x-y)*a;
            cout << ans << endl;
        }

        
    }
}