// https://codeforces.com/contest/1345/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        if(n == 1 or m == 1) {
            cout << "YES" << endl;
        } else if(n == 2 and m == 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}