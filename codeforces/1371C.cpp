// https://codeforces.com/contest/1371/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define ll long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        ll v, c, n, m;
        cin >> v >> c >> n >> m;

        ll s = min(n, abs(v-c));
        if(v > c) {
            v -= s;
        } else if(c > v) {
            c -= s;
        }
        n -= s;

        if(min(v, c) < m) {
            cout << "No" << endl;
            continue;
        } else {
            if(v > c) {
                c -= m;
            } else {
                v -= m;
            }
        }

        if(v+c >= n) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }    
}
