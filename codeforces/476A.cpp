// https://codeforces.com/contest/476/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = m; i <= n; i += m) {
        int h = i;
        if(h <= n and 2*h >= n) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}