// https://codeforces.com/contest/1325/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define ll long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll u, v;
    cin >> u >> v;

    if(u > v) {
        cout << -1 << endl;
    } else if(u%2 != v%2) {
        cout << -1 << endl;
    } else if(u == 0 and v == 0) {
        cout << 0 << endl;
    } else if(u == v) {
        cout << 1 << endl;
        cout << u << endl;
    } else {
        ll x = (v-u)/2;
        if(u&x) {
            cout << 3 << endl;
            cout << u << " " << x << " " << x << endl;
        } else {
            cout << 2 << endl;
            cout << (u|x) << " " << x << endl;
        }
    }
}
