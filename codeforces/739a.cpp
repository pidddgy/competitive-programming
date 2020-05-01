// https://codeforces.com/contest/739/problem/A

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

    int mi = INT_MAX;
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;

        mi = min(mi, r-l+1);
    }

    cout << mi << endl;
    for(int i = 0; i < n; i++) {
        cout << i%mi << " ";
    }
    cout << endl;
}