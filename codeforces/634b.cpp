// https://codeforces.com/contest/1335/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    const string alpha = "abcdefghijklmnopqrstuvwxyz";

    int t;
    cin >> t;

    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;

        string rep;
        for(int i = 0; i < b; i++) {
            rep += alpha[i];
        }

        for(int i = 0; i < n; i++) {
            cout << rep[i%b];
        }
        cout << endl;
    }
}