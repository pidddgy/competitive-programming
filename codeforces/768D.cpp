// https://codeforces.com/contest/768/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= 100; i++) {
        for(int x: a) {
            cout << x << " ";
        }
        cout << endl;
        for(int j = 0; j < n; j++) {
            a[j] ^= x;
        }

        sort(a.begin(), a.end());
    }
}