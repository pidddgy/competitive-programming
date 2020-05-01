// https://codeforces.com/contest/643/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if(k <= n or n <= 4) {
        cout << -1 << endl;
        return 0;
    }

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    set<int> nabcd;
    for(int i = 1; i <= n; i++) {
        if(i != a and i != b and i != c and i != d) {
            nabcd.emplace(i);
        }
    }

    cout << a << " " << c << " ";
    for(int x: nabcd) {
        cout << x << " ";
    }
    cout << d << " " << b << endl;

    cout << c << " " << a << " ";
    for(int x: nabcd) {
        cout << x << " ";
    }
    cout << b << " " << d << endl;
}