// https://codeforces.com/contest/317/problem/A

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define ll long long
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll x, y, m;
    cin >> x >> y >> m;

    if(max(x, y) >= m) {
        cout << 0 << endl;
        return 0;
    }
    if (x > y) {
        swap(x, y);
    }
    if(y <= 0) {
        cout << -1 << endl;
        return 0;
    }

    ll ops = 0;

    watch(x)
    watch(y)
    watch(1000000000000000000/1)
    if(x < 0) {
        watch(-x)
        ops = ((-x)/y);

        watch(ops)
        x += ops*y*1LL;
    }

    watch(x)
    watch(y)

    while(max(x, y) < m) {
        x += y;
        if(x>y) {
            swap(x, y);
        }

        ops++;
    }
    if(max(x, y) < m) {
        cout << -1 << endl;
    } else {
        cout << ops << endl;
    }
}